/*
Write a program dynamically allocates an array of that size to hold
floating-point values. Using pointer notation, initialize all the elements of
the array so that the value of the element at index position n is 1.0/(n+1)2.
 the sum of the elements using pointer notation, multiply the sum by 6, and
output the square root of that result.
*/

#include <iomanip>
#include <iostream>
//#include <locale>         // For toupper()
//#include <memory>         // For smart pointers
//#include <algorithm>      // sts::count

#include <vector>           // For vector
//#include <array>
#include <cassert>          // <assert.h>  
#include <cmath>            // sqrt
#include <cstdlib>          //


//using std::array;
using std::cin;
using std::cout;
using std::endl;
//using std::shared_ptr;

int main() {
    size_t array_size = 0;
    double sum = 0.0;

    while (array_size < 1) {
    cout << "Enter a number for array size:";
    cin >> array_size;

    }

    assert(array_size > 0);

    std::vector<double> mya;


    for (size_t i = 0; i < array_size; i++) {  //fill vector with array_size values
        double num = 1.0/((i+1) * 2);
        mya.push_back(num);

    }

    for (size_t i = 0; i < mya.size(); i++) {
        cout << mya.at(i) << endl;
        sum = sum + mya.at(i);
    }

    double res = std::sqrt(sum * 6);
    cout << "Sum = " << sum << endl;
    cout << "Res = " << res << endl;
}