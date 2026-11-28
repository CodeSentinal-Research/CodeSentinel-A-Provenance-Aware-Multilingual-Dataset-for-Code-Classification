Here is the C++ code that should solve the problem.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count[3] = {0, 0, 0};
    int length = s.length();
    for (int i = 0; i < length; i++) {
        count[s[i] - 'a']++;
    }

    if (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        cout << (length * (length + 1) / 2 - count[0] * (count[0] + 1) / 2 - count[1] * (count[1] + 1) / 2 + count[2]) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

This code first reads the input string, then counts the occurrences of 'a', 'b', and 'c'. It then checks if all characters are present. If they are, it calculates the number of substrings that contain all three characters using the formula:

(n*(n+1)/2 - a*a - b*b + ab)

where n is the length of the string, a is the count of 'a', b is the count of 'b', and ab is the count of 'ab'. The result is the number of substrings containing at least one occurrence of each character.

If not all characters are present, it prints 0.