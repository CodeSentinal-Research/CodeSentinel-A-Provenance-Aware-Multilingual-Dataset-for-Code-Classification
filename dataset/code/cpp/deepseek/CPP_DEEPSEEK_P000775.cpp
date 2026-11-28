#include <iostream>
using namespace std;

void printBinaryStrings(int N) {
    if (N == 1) {
        cout << "0" << " " << "1" << endl;
    } else if (N == 2) {
        cout << "00" << " " << "01" << " " << "10" << " " << "11" << endl;
    } else {
        string str = "0";
        for (int i = 1; i < N; i++) {
            str += "01";
        }
        str += "1";
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));
    }
}

int main() {
    int N;
    cin >> N;
    printBinaryStrings(N);
    return 0;
}