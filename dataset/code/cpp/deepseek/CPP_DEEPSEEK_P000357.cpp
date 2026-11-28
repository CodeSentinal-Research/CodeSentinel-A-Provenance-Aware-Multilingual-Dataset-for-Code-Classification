#include <iostream>
using namespace std;

int main() {
    string S;
    char C;

    cin >> S >> C;

    int count = 0;
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == C) {
            count++;
        }
    }

    cout << count;

    return 0;
}