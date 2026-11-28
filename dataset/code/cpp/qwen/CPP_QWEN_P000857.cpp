#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N > 0 && (N & (N - 1)) == 0) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
