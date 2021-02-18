/*
Write a program dynamically allocates an array of that size to hold
floating-point values. Using pointer notation, initialize all the elements of
the array so that the value of the element at index position n is 1.0/(n+1)2.
 the sum of the elements using pointer notation, multiply the sum by 6, and
output the square root of that result.
*/

#include <iomanip>
#include <iostream>
//#include <locale>  // For toupper()
//#include <memory>  // For smart pointers
//#include <vector>  // For vector container
//#include <array>
#include <assert.h>

#include <cmath>  // sqrt
#include <sstream>
#include <string>

// using std::array;
using std::cin;
using std::cout;
using std::endl;
// using std::shared_ptr;

int main() {
    size_t array_size = 0;
    double sum = 0.0;
    std::string line;

    while (array_size <= 0) {
        cout << "Enter a number for array size:";
        std::getline(cin, line);
        std::stringstream sline(line);
        if (sline >> array_size) {
            if (array_size <= 0) continue;
            else break;
        }
    }

    assert(array_size > 0);
    double* mya = new double[array_size];

    for (size_t i = 0; i < array_size; i++) {
        double num = 1.0 / ((i + 1) * 2);
        *(mya + i) = num;  // mya[i] = num;
    }

    for (size_t i = 0; i < array_size; i++) {
        cout << mya[i] << endl;
        sum = sum + *(mya + i);
    }

    double sum6 = (sum * 6);
    double res = std::sqrt(sum6);
    cout << "Sum = " << sum << endl;
    cout << "Res = " << res << endl;

    delete[] mya;
}