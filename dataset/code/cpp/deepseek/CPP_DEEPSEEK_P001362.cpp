Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str;
    int K;
    cin >> str >> K;

    vector<int> count(26, 0);
    for (char c : str) {
        count[c - 'a']++;
    }

    int odd = 0;
    for (int cnt : count) {
        odd += cnt % 2;
    }

    if (odd > K) {
        cout << "NO" << endl;
    } else {
        cout << (odd % 2 == 0 || odd <= K) << endl;
    }

    return 0;
}

In this code, we first read the string and the number of partitions K from the standard input.

Then, we create a count array where each index i represents the number of times the character 'a' + i is present in the string.

We calculate the number of characters that are odd. If this number is greater than K, we can't partition all characters into K non-empty palindrome strings.

Finally, we print "YES" if and only if the number of odd characters is either 0 or K or both. If the number of odd characters is greater than K, we print "NO".