// Using smart pointers

#include <iomanip>
#include <iostream>
#include <locale>  // For toupper()
#include <memory>  // For smart pointers
#include <vector>  // For vector container

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;

int main() {
    vector<shared_ptr<vector<double>>> records;  // Temperature records by days, vector of pointers to vectors of doubles
    size_t day = 1;                               // Day number
    char answer;                               // Response to prompt
    double t = 0.0;                                  // A temperature

    while (true) {                               // Collect temperatures by day

        
        auto pDay = std::make_shared<vector<double>>();     // Vector to store current day's temperatures created on the heap
        records.push_back(pDay);                            // Save pointer in records vector

        cout << "Enter the temperatures for day " << day++
             << " separated by spaces. Enter 1000 to end:\n";

        while (true) {  // Get temperatures for current day
            
            std::cin >> t;
            if (t == 1000.0) break;

            pDay->push_back(t);
        }

        cout << "Enter another day's temperatures (Y or N)? ";
        std::cin >> answer;

        if (toupper(answer) == 'N') break;
    }

    double total = 0.0;
    size_t count = 0;
    day = 1;
    cout << std::fixed << std::setprecision(2) << endl;

    for (auto record : records) {
        cout << "\nTemperatures for day " << day++ << ":\n";
        
        for (auto temp : *record) {
            total += temp;
            cout << std::setw(6) << temp;
            if (++count % 5 == 0) cout << endl;
        }
        cout << "\nAverage temperature: " << total / count << endl;
        total = 0.0;
        count = 0;
    }
}
