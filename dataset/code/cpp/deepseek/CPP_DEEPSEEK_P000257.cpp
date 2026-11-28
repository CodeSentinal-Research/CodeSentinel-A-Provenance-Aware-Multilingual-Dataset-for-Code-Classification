Here is the C++ code:

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

This code uses the C++ `sort` function from the `algorithm` library to sort the characters in each string. It then compares the sorted strings. If they are equal, the strings are anagrams of each other.