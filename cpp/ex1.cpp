#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int a;
    int c = 0;
    const long d = 10000000L;

    cout << "Enter the number between 5 and 10" << endl;
    cin >> a;

    if (a < 5 || a > 10)
    {
        cout << "Wrong number" << endl;
        system("PAUSE");
        return 0;
    }

    for (size_t i = 1; i <= a; i++)
    {
        c = c + i;
    }


    cout << "The sum of the first " << a << " numbers are " << c << endl;
    cout << "\"Least \'said\' \\\n\t\tsoonest \'mended\'.\"" << endl;
    system("PAUSE");

    return 0;
}