#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateStrings(char* characters, int n, int k) {
    vector<char> data(characters, characters + n);
    sort(data.begin(), data.end());
    do {
        string s;
        for (int i = 0; i < k; i++) {
            s += data[i];
        }
        cout << s << endl;
    } while (next_permutation(data.begin(), data.end()));
}

int main() {
    int n, k;
    cout << "Enter the number of distinct characters: ";
    cin >> n;
    cout << "Enter the length of the strings: ";
    cin >> k;

    char characters[n];
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    generateStrings(characters, n, k);

    return 0;
}