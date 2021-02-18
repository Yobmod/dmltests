// Calculating primes using dynamic memory allocation

#include <iostream>
#include <iomanip>
#include <cmath>                       // std::sqrt
#include <algorithm>                    // std::count

using std::cout;
using std::cin;
using std::endl;

int main(){  

    size_t max = 0;                       // Number of primes required  

    cout << "How many primes would you like? "; 
    cin >> max;                    // Read number required and...  

    unsigned long long* primes {new unsigned long long[max]};  // ...allocate memory for them  

    *primes = 2uLL;                                            // Insert three seed primes...  
    *(primes + 1) = 3uLL;  
    *(primes + 2) = 5uLL;  
    size_t count = max - std::count(primes, primes + max, 0);  // Count of primes found so far (count empty array elements and substract from array size)


    unsigned long long trial = *(primes + 2);                  // Candidate prime  
    bool isprime = false;                                      // Indicates when a prime is found  
    unsigned long long limit = 0;                               // Stores square root of trial 

    do {    
        trial += 2;                                              // Next value for checking    
        limit = static_cast<unsigned long long>(std::sqrt(trial));    
        size_t i = 0;      
                                               // Index to primes array    
        do {      
            isprime = trial %  *(primes + i) > 0;                  // False for exact division    
        } while (primes[++i] <= limit && isprime);    
        
        if (isprime) {                                         // We got one...      
        *(primes + count++) = trial;
        }                           // ...so save it in primes array  
    } while (count < max);  

    // Output primes 10 to  a line  
    for (size_t i = 0 ; i < max ; ++i) {    
        cout << std::setw(10) << *(primes + i);  
  
        if ((i + 1) % 10 == 0) {                                   // After every 10th prime...  
        cout << endl;                                // ...start a new line  
        }
    }  
    cout << endl;  
    
    delete[] primes;                                           // Free up memory...  
    primes = nullptr;                                          // ... and reset the pointer

}