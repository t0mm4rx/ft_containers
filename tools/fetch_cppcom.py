"""
	This scripts parses http://www.cplusplus.com/ to fetch all containers methods.
"""
from bs4 import BeautifulSoup
import requests

"""
	Download the given container page, listing all its methods.
"""
def get_container_listing(container):
	url = "http://www.cplusplus.com/reference/{}/{}/".format(container, container)
	r = requests.get(url)
	doc = BeautifulSoup(r.text, features="html.parser")
	result = []
	for link in doc.select(".links"):
		if (len(link.select(".C_cpp11")) == 0):
			result.append({
				"name": link.select("b")[0].text,
				"url": "http://www.cplusplus.com{}".format(link.select("a")[0]['href'])
			})
	return result

"""
	Format template pre.
"""
def format_template(template):
	return ' '.join(template.replace('\n', '').replace('\t', '').split()).split('; ')

"""
	Download a method page, and get its templates.
"""
def get_method_template(obj):
	r = requests.get(obj['url'])
	doc = BeautifulSoup(r.text, features="html.parser")
	result = []
	if (len(doc.select("[title='C++98']")) > 0):
		for template in doc.select("[title='C++98']")[0].select("pre"):
			for a in format_template(template.text):
				result.append(a)
	else:
		for template in doc.select(".C_prototype")[0].select("pre"):
			for a in format_template(template.text):
				result.append(a)
	obj['templates'] = result

"""
	Get all methods for a given container.
"""
def get_container(container):
	methods = get_container_listing(container)
	for method in methods:
		get_method_template(method)
	return methods

"""
	Create a file and put all container methods inside.
"""
def handle_container(container):
	methods = get_container(container)
	with open("Methods{}.md".format(container.capitalize()), "w+") as file:
		file.write("# {}\n".format(container.capitalize()))
		for method in methods:
			file.write("## {}\n".format(method['name']))
			for template in method['templates']:
				file.write("- [ ] {}\n".format(template))

# handle_container("vector")
# handle_container("map")
# handle_container("list")
# handle_container("stack")
handle_container("queue")