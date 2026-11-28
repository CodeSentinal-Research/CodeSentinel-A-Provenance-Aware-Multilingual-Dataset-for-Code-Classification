#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> strings(N);

    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    string shortestString = *min_element(strings.begin(), strings.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    for (int i = 0; i < N; i++) {
        if (strings[i] == shortestString) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}