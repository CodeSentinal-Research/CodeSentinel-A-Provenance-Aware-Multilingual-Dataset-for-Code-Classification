Here is the C++ code that solves the problem:

#include <iostream>
#include <cmath>
using namespace std;

int titleToNumber(string columnTitle) {
    int result = 0;
    for (int i = 0; i < columnTitle.size(); i++) {
        result += (columnTitle[i] - 'A' + 1) * pow(26, columnTitle.size() - i - 1);
    }
    return result;
}

int main() {
    string columnTitle;
    cin >> columnTitle;
    cout << titleToNumber(columnTitle);
    return 0;
}

In this code, we first initialize a result variable to 0. Then, we iterate over the string columnTitle. For each character in the string, we add (columnTitle[i] - 'A' + 1) * pow(26, columnTitle.size() - i - 1) to the result. This formula is used to convert the Excel column title to its corresponding column number. The 'A' is subtracted by 'A' to get the value of 'A' (1), 'B' is subtracted by 'A' (1) and so on. The pow function is used to raise 26 to the power of the number of times the string is iterated over (i.e., the length of the string).