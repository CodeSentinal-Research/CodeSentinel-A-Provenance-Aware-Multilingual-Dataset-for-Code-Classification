#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char dest, char aux, int& moves) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << dest << endl;
        moves++;
        return;
    }
    towerOfHanoi(n - 1, source, aux, dest, moves);
    cout << "Move disk " << n << " from rod " << source << " to rod " << dest << endl;
    moves++;
    towerOfHanoi(n - 1, aux, dest, source, moves);
}

int main() {
    int n;
    cin >> n;
    int moves = 0;
    towerOfHanoi(n, 'A', 'C', 'B', moves);
    cout << moves << endl;
    return 0;
}
