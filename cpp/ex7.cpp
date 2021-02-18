#include <iostream>

int main()
{
    size_t count;
    std::cout << "How many heights will you enter? ";
    std::cin >> count;
    int height[count]; // Create empty array of count elements

    // Read the heights
    size_t entered = 0;
    int value;

    while (entered < count)
    {
        std::cout << "Enter a height: ";
        std::cin >> value;

        if (value >= 0) // Make sure value is positive or 0
        {
            height[entered] = value;
            ++entered;
            // std::cout << value;
        }
        else if (value < 0)
        {
            height[entered] = value;
            ++entered;
            std::cout << value << "A height must be positive - try again.\n";
        }
        else
        {
           std::cout << "A height must be integer - try again.\n"; 
        }
        
    }

    // Calculate the sum of the heights
    unsigned int total=0;
    for (size_t i=0; i < count; ++i)
    {
        total += height[i];
    }

    for (size_t x= 0; x < count; x++)
    {
            std::cout << height[x] << std::endl;

    }
    std::cout << "The average height is " << total / count << std::endl;
}