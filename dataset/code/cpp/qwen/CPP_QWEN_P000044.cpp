#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) cout << i << (i == 1 ? "" : " ");
    cout << endl;
    return 0;
}
