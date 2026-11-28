#include <iostream>
#include <string>
using namespace std;

void printLexicographical(int current, int N) {
    if (current > N) return;
    cout << current << endl;
    for (int i = 0; i <= 9; ++i) {
        int next = current * 10 + i;
        if (next > N) break;
        if (next == 0) continue; // Avoid infinite loop for 0
        printLexicographical(next, N);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 9; ++i) {
        printLexicographical(i, N);
    }
    return 0;
}
