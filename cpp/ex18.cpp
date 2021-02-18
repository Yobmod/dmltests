// Accessing characters in a string

#include <iostream>
#include <locale>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main() {
    string text;  // Stores the input
    std::cout << "Enter a line of  text:\n";
    std::getline(cin, text);  // Read a line including spaces

    int vowels = 0;      // Count of vowels
    int consonants = 0;  // Count of consonants

    // for (size_t i = 0; i < text.length(); ++i) {   text[i]...
    for (const auto& i: text) {
        if (isalpha(i)) {  // Check for a letter

            switch (std::tolower(i)) {  // Convert to lowercase

                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++vowels;
                    break;
                default:
                    ++consonants;
                    break;
            }
        }
    }
    cout << "Your input contained " 
            << vowels << " vowels and "
            << consonants << " consonants." 
            << endl;
}