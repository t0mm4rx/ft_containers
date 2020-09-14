#include <vector>
#include <iostream>

void print_vector(std::vector<int> vec)
{
    std::vector<int>::iterator it;

    std::cout << "size " << vec.size() << ": ";
    it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " - ";
        ++it;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "-- Testing STL containers --" << std::endl;
    std::vector<int> vector;
    vector.push_back(-42);
    vector.push_back(21);
    vector.push_back(6);
    print_vector(vector);
    std::cout << "-- pop_back --" << std::endl;
    vector.pop_back();
    print_vector(vector);
    std::cout << "-- max_size: " << vector.max_size() << " --" << std::endl;
    std::cout << "-- capacity: " << vector.capacity() << " --" << std::endl;
    vector.push_back(18);
    vector.push_back(69);
    vector.push_back(667);
    print_vector(vector);
    std::cout << "-- capacity: " << vector.capacity() << " --" << std::endl;
    std::cout << "-- resize(3) --" << std::endl;
    vector.resize(3);
    print_vector(vector);
    std::cout << "-- resize(10, 42) --" << std::endl;
    vector.resize(10, 42);
    print_vector(vector);
    std::cout << "-- empty: " << vector.empty() << " --" << std::endl;
    std::cout << "-- reserve(1) --" << std::endl;
    vector.reserve(0);
    print_vector(vector);
    std::cout << "-- vector[4]: " << vector[4] << " --" << std::endl;
    std::cout << "-- vector.at(2): " << vector.at(2) << " --" << std::endl;
    std::cout << "-- vector.front(): " << vector.front() << " --" << std::endl;
    std::cout << "-- vector.back(): " << vector.back() << " --" << std::endl;
    std::cout << " -- vector.clear() --" << std::endl;
    vector.clear();
    print_vector(vector);
    std::cout << "-- empty: " << vector.empty() << " --" << std::endl;
    std::cout << "-- capacity: " << vector.capacity() << " --" << std::endl;
    return (0);
}