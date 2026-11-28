Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= 3) {
            result += 2;
        } else {
            result += 2 * (2 << (i - 3));
        }
    }
    cout << result << endl;
    return 0;
}

This program calculates the number of valid strings of length N consisting only of vowels such that the characters appear in non-decreasing lexicographical order.

The logic behind this program is that for each vowel at position i, we have two options:

1. We can include it in the string, which will lead to 2 choices (either the vowel itself or a space).
2. We can leave it out, which will lead to 2 * 2^(i-1) choices (since we have already used 2^(i-1) choices to include the vowel in the string).

So, the total number of choices for each vowel position is 2 + 2 * 2^(i-3), where i is the position of the vowel in the string. We then sum up these choices for all vowels to get the total number of valid strings.