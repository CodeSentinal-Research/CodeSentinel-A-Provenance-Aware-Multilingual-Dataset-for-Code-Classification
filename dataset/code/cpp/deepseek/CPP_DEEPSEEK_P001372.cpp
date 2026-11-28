#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> nums;
    while (n--) {
        int num;
        cin >> num;
        if (nums.find(num) != nums.end()) {
            cout << "YES" << endl;
            return 0;
        }
        nums.insert(num);
    }
    cout << "NO" << endl;
    return 0;
}