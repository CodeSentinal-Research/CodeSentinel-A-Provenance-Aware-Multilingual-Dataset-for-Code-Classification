Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateBinaryStrings(vector<string>& result, string s, int n, int N) {
    if (s.length() == N) {
        result.push_back(s);
        return;
    }
    if (s.length() < N) {
        generateBinaryStrings(result, s + "0", n, N);
        if (s.length() == 0 || s[s.length() - 1] == '0') {
            generateBinaryStrings(result, s + "1", n, N);
        }
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    vector<string> result;
    generateBinaryStrings(result, "", N, N);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

This program uses a recursive function to generate all binary strings of a given length. It starts with an empty string and appends '0' or '1' to the end of it until the length is equal to N. If the string is empty (i.e., it is the first character), then the program checks whether the previous character is '0'. If it is '0', then the program recursively appends '0' and '1' to the end of the string. If it is not '0', then the program only appends '0' to the end of the string.