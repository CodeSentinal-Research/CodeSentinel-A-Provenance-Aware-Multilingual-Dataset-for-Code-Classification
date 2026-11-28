#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long temp = N;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    temp = N;
    long long sum = 0;
    while (temp > 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }
    
    cout << (sum == N ? "true" : "false") << endl;
    return 0;
}
