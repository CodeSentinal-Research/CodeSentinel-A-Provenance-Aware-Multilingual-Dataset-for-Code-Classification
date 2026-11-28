#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> strings(N);

    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    for (int i = 0; i < N; i++) {
        if (strings[i] == "") {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}