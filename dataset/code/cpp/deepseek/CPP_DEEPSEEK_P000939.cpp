#include <iostream>
using namespace std;

bool canWinNim(int N) {
    return N % 4 != 0;
}

int main() {
    int N;
    cout << "Enter the number of stones: ";
    cin >> N;

    if (canWinNim(N)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}