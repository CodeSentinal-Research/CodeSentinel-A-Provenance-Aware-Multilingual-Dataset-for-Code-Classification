#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int longestUncommonSubsequence(string A, string B) {
    if (A == B) {
        return -1;
    }
    else {
        return max(A.size(), B.size());
    }
}

int main() {
    string A, B;
    cout << "Enter string A: ";
    cin >> A;
    cout << "Enter string B: ";
    cin >> B;
    int result = longestUncommonSubsequence(A, B);
    cout << "Length of the longest uncommon subsequence: " << result << endl;
    return 0;
}
This code defines a function `longestUncommonSubsequence` that calculates the length of the longest uncommon subsequence of two strings. If the two strings are equal, it returns -1, otherwise, it returns the maximum of the sizes of the two strings. The `main` function handles input for the strings and prints the result of the `longestUncommonSubsequence` function.