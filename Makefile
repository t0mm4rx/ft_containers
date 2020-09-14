TARGET=test

all: ${TARGET}

${TARGET}:
	clang++ -Werror -Wextra -Wall -fsanitize=address -g3 main.cpp -o ${TARGET}

clean:
	rm -rf *.dSYM

fclean: clean
	rm -rf ${TARGET}

re: fclean all

.PHONY: all ${TARGET}