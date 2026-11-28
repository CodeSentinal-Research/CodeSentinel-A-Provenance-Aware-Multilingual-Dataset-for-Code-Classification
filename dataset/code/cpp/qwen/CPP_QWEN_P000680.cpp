#include <iostream>
using namespace std;
void printNums(int curr, int n) {
    if(curr < 1) return;
    cout << curr << " ";
    printNums(curr - 1, n);
}
int main() {
    int n; cin >> n;
    printNums(n, n);
    cout << endl;
    return 0;
}
