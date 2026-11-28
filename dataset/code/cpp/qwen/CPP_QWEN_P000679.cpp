#include <iostream>
using namespace std;
void printNums(int curr, int n) {
    if(curr > n) return;
    printNums(curr + 1, n);
    cout << curr << " ";
}
int main() {
    int n; cin >> n;
    printNums(1, n);
    cout << endl;
    return 0;
}
