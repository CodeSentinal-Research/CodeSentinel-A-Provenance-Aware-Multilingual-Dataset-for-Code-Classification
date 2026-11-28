#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int size = 4 * numRows - 2;
    int len = s.length();
    string ret(len, ' ');

    int k = 0;
    int x = 0;

    vector<int> positions(numRows, 0);

    for (int i = 0; i < len; i += 4 * numRows - 2) {
        for (int j = 0; j < numRows && i + j < len; j++) {
            ret[k++] = s[i + j];
        }
        positions[j]++;
    }

    for (int i = 1; i < numRows; i++) {
        int j = positions[i];
        int step = 2 * (numRows - i);
        while (i + j < len) {
            ret[k++] = s[i + j];
            j += step;
        }
    }

    return ret;
}

int main() {
    string s;
    int numRows;

    cin >> s >> numRows;

    cout << convert(s, numRows) << endl;

    return 0;
}
This C++ code takes in a string and the number of rows to use for the zigzag pattern as inputs, and returns the zigzag converted string. The algorithm works by iterating through the input string in a way that alternates between the rows of the zigzag pattern. Each step in the loop adds a character to the result string and then updates the positions of the current row.