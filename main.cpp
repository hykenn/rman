#include <iostream>
#include <string>
#include <unordered_map>


int romanToInt(const std::string& s) {

    std::unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int n = s.length();


    for (int i = 0; i < n; ++i) {
        if (i < n - 3 && s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == s[i + 3]) {
            std::cerr << "Error: Roman numeral '" << s[i] << "' is repeated 4 times. It must not be repeated more than 3 times." << std::endl;
            return -1;
        }
    }

    for (int i = 0; i < n; ++i) {

        if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        }

        else {
            result += roman[s[i]];
        }
    }

    return result;
}

int main() {
    std::string roman;
    std::cout << "Enter a Roman numeral: ";
    std::cin >> roman;

    int result = romanToInt(roman);
    if (result != -1) {
        std::cout << "The equivalent Hindu-Arabic numeral is: " << result << std::endl;
    }

    return 0;
}
