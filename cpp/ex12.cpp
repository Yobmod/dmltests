// Calculating primes using pointer notation

#include <iostream>
#include <iomanip>
#include <algorithm>  // sts::count

using std::cout;
using std::cin;
using std::endl;

int main()
{

    const size_t max = 100;        // Number of primes required
    long primes[max] = {2L, 3L, 5L, 7L}; // First x primes defined
    size_t count = max - std::count(primes, primes + max, 0);              // Count of primes found so far (count empty array elements and substract from array size)
    long trial = primes[count - 1];                // Candidate prime, initialze as latest found
    bool isprime = true;

    // Indicates when a prime is foundu
    do {
        trial += 2; // Next value for checking
        size_t i = 0; // Index to primes array

        do {                                            // Try dividing the candidate  by all the primes we have
            isprime = trial % *(primes + i) > 0;        // False for exact division
        } while (++i < count && isprime);

        if (isprime) {                                  // We got one...
            *(primes + count++) = trial;               // ...so save it in primes array
        }

    } while (count < max);

    // Output primes 10 to a line
    cout << "The first " << max << " primes are:" << endl;

    for (size_t i = 0; i < max; ++i) {
        cout << std::setw(7) << *(primes + i);

        if ((i + 1) % 10 == 0) // Newline after every 10th prime
            cout << endl;
    }
    cout << endl;
}