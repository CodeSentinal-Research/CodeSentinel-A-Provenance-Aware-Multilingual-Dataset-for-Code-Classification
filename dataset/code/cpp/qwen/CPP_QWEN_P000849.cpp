#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N & 1) cout << "Odd" << endl;
    else cout << "Even" << endl;
    return 0;
}
