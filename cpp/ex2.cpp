#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int yards{}, feet{}, inches{}, total_inches {};
    const unsigned int feet_per_yard {3U};
    const unsigned int inches_per_foot = 12U;

    cout << "Enter a distance as yards, feet, and inches " << "with the three values separated by spaces:" << endl;
    cin >> yards >> feet >> inches;

    total_inches = inches + inches_per_foot * (yards * feet_per_yard + feet);
    cout << "The distances corresponds to " << total_inches << " inches.\n";

    cout << "Enter a distance in inches: ";
    cin >> total_inches;

    feet = total_inches / inches_per_foot;
    inches = total_inches % inches_per_foot;
    yards = feet / feet_per_yard;
    feet = feet % feet_per_yard;

    cout << "The distances corresponds to "
              << yards << " yards "
              << feet << " feet "
              << inches << " inches." 
              << endl;
    
    return 0;
}