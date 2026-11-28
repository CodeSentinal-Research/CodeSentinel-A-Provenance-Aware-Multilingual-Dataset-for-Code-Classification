Here is the required C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> shortestDistance(string s, char c) {
    vector<int> distances(s.length(), 0);
    int prev = -1;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            if (prev != -1) {
                for (int j = prev; j <= i; ++j) {
                    distances[j]++;
                }
            }
            prev = i;
        }
    }

    if (prev != -1) {
        for (int j = prev; j < s.length(); ++j) {
            distances[j]++;
        }
    }

    return distances;
}

int main() {
    string s;
    char c;

    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter a character: ";
    cin >> c;

    vector<int> distances = shortestDistance(s, c);

    cout << "Shortest distances:" << endl;
    for (int distance : distances) {
        cout << distance << " ";
    }
    cout << endl;

    return 0;
}

This code prompts the user for a string and a character, then calculates and prints the shortest distance from each character in the string to the given target character.