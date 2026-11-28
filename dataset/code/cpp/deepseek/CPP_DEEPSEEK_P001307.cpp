#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    int police = 0, thieves = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') {
            police++;
        } else {
            thieves++;
            if (police > 0) {
                police--;
                thieves++;
            }
        }
    }

    cout << thieves << "\n";

    return 0;
}