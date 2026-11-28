#include <iostream>
using namespace std;

int findPosition(int N) {
    int position = 0;
    while ((N & 1) == 0) {
        N >>= 1;
        position++;
    }
    return position;
}

int main() {
    int N;
    cout << "Enter an integer: ";
    cin >> N;

    if(N >= 1 && N <= 2147483647) {
        int position = findPosition(N);
        cout << "The position of the set bit is: " << position;
    } else {
        cout << "Invalid input!";
    }

    return 0;
}