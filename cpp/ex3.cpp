#include <iostream>

int main()
{
    int values[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const size_t length {sizeof(values) / sizeof(values[0])};

    std::cout << "There are " << length << " elements in the array." << std::endl;

    int sum{};
    for (size_t i{}; i < length); ++i)
    {
        sum += values[i];
    }

    std::cout << "The sum of the array elements is " << sum << std::endl;
}