#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> result;
    int N = s.size();

    int i = 0, j = N;

    for (int k = 0; k < N; k++) {
        if (s[k] == 'I') {
            result.push_back(i++);
        } else {
            result.push_back(j--);
        }
    }

    for (int k = N-1; k >= 0; k--) {
        if (s[k] == 'I') {
            result.push_back(i++);
        } else {
            result.push_back(j--);
        }
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}