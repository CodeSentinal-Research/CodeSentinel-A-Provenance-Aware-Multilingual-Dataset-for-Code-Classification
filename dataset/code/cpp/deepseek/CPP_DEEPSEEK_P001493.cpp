Here is the required C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> shortestDistance(string str, char c) {
    vector<int> res(str.length(), -1);
    int lastFound = -1;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == c) {
            lastFound = i;
        }
        else if (lastFound != -1) {
            res[i - lastFound] = i - lastFound;
        }
    }

    return res;
}

int main() {
    string str;
    char c;

    cin >> str >> c;

    vector<int> res = shortestDistance(str, c);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

This program reads a string and a character as input, calls the `shortestDistance` function, and then prints the results. The `shortestDistance` function finds the distance to the nearest occurrence of the character in the string, storing the distance in a vector and returns it. If a character is not found in the string, the distance is -1.