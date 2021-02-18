
#include <cmath>
#include <cstdlib>



#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::right;
using std::left;
using std::fixed;
using std::defaultfloat;

#include <iomanip>
using std::setprecision(n);
std::setwidth(int);


#include<memory>
std:unique_ptr
std::shared_ptr
std:weak_ptr
std::make_shared<_type>()
.get()          // gets the address of pointer
.reset()        // set pointer to nullptr.   If unique_ptr, deleted memory
std::move()     // change pointer address, required for unique_ptr
.expired()      //check if weak_ptr still fits
.lock()         // created shared from  weak_ptr

#include<vector>
.size()
.at(int c)
.push_back(val)
.pop_back(val)
.reserve(int)
.clear()

#include<array>
.size()
.at(int c)

#include <algorithm>
using std::count;

#include <locale>
isupper(int c)
isalpha(int c)
isalnum(int c)
isspace(int c)