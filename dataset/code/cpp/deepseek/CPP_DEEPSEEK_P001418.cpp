#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    string allowed;
    int N;
    cin >> allowed >> N;

    set<char> allowedChars(allowed.begin(), allowed.end());

    int count = 0;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bool consistent = true;
        for (char c : word) {
            if (allowedChars.find(c) == allowedChars.end()) {
                consistent = false;
                break;
            }
        }
        if (consistent) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}