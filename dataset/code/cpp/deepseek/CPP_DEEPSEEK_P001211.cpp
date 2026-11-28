#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        total += num;
    }
    
    if (total % k != 0) {
        cout << "NO";
        return 0;
    }
    
    total /= k;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += abs(abs(total - abs(cin.fail())));
    }
    
    if (currSum % 2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}