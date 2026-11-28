#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long total = a + b + c;
    long long maxVal = max({a, b, c});
    
    if (maxVal > total - maxVal) {
        cout << total - maxVal << endl;
    } else {
        cout << total / 2 << endl;
    }
    
    return 0;
}
