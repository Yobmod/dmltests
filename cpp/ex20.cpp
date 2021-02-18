// Using static variables

#include <iomanip>
#include <iostream>

//#include <locale>         // For toupper()
//#include <memory>         // For smart pointers
//#include <algorithm>      // sts::count
//#include <vector>         // For vector
//#include <array>
//#include <cassert>        // <assert.h>
//#include <cmath>          // sqrt
//#include <cstdlib>         //

using std::cin;
using std::cout;
using std::endl;
// using std::array;
// using std::shared_ptr;


long next_Fibonacci();

int main(int argc, char* argv[]) {

    if (argc > 1) {
        for (int i = 0; i < argc; ++i) {
            cout << argv[i] << endl;
        }
    }

    size_t count = 0;
    cout << "Enter the number of Fibonacci values to be generated: ";
    cin >> count;
    cout << "The Fibonacci  Series:\n";

    for (size_t i = 0; i < count; ++i) {
        cout << std::setw(10) << next_Fibonacci();
        if (!((i + 1) % 8))  // After every 8th output...
            cout << endl;    // ...start a new  line
    }
    cout << endl;
}

// Generate the next number in the Fibonacci series
long next_Fibonacci() {
    static long last;                // Last number in sequence
    static long last_but_one = 1L;    // Last but one in sequence
    long next = last + last_but_one;  // Next is sum of the last two

    last_but_one = last;  // Update last but one
    last = next;          // Last is new one
    return last;          // Return the new value
}
