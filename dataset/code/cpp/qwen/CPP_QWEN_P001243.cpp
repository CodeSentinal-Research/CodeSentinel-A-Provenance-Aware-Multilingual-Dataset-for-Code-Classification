#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> bills(n);
    for (int i = 0; i < n; ++i) cin >> bills[i];
    
    int five = 0, ten = 0;
    bool possible = true;
    
    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five > 0) {
                five--;
                ten++;
            } else {
                possible = false;
                break;
            }
        } else if (bill == 20) {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                possible = false;
                break;
            }
        }
    }
    
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}
