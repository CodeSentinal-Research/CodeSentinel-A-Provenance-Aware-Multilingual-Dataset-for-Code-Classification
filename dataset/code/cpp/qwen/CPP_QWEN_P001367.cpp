#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    // First player wins if n % (k + 1) != 0
    cout << (n % (k + 1) != 0 ? "FIRST" : "SECOND") << endl;
    return 0;
}
