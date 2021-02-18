#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stdexcept>

int main()
{
    unsigned int limit;
    std::cout << "This program calculates n! and the sum of the integers"
              << " up to n for values 1 to limit.\n";

    std::cout << "What upper limit for n would you like? ";

    std::cin >> limit; // Output column headings

    if (limit < 0 || limit > 20)
    {
        throw std::runtime_error("Input must be between 0 and 20\n");
    }

    assert(limit <= 20);
    
    std::cout << std::setw(8) << "integer"
              << std::setw(8) << " sum"
              << std::setw(20) << " factorial"
              << std::endl;

    unsigned long long factorial = 1LL;
    size_t sum{};


    for (size_t n = 1; n <= limit; ++n)
    {
        sum += n;       // Accumulate sum to current n
        factorial *= n; // Calculate n! for current n
        std::cout << std::setw(8) << n
                  << std::setw(8) << sum
                  << std::setw(20) << factorial
                  << std::endl;
    }

    return 0;
}