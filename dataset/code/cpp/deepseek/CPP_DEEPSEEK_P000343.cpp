#include <iostream>
#include <unordered_map>
using namespace std;

bool checkAlmostEquivalent(string word1, string word2) {
    unordered_map<char, int> count1, count2;
    for (char c : word1) ++count1[c];
    for (char c : word2) ++count2[c];

    for (char c : word1) {
        if (abs(count1[c] - count2[c]) > 3) {
            return false;
        }
    }

    for (char c : word2) {
        if (abs(count1[c] - count2[c]) > 3) {
            return false;
        }
    }

    return true;
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    if (checkAlmostEquivalent(word1, word2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
This C++ program defines a function `checkAlmostEquivalent` which checks whether two strings are almost equivalent by comparing the frequency of each character in the two strings. The function uses an unordered map to count the frequency of each character in the strings. If the absolute difference in frequency of any two characters is greater than 3, the function returns `false`. Otherwise, it returns `true`.

In the main function, the program reads two strings from the standard input and checks if they are almost equivalent by calling the `checkAlmostEquivalent` function. If the strings are almost equivalent, the program prints "Yes", otherwise it prints "No".