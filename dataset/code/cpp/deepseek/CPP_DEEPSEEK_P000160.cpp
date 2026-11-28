#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    unordered_set<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (nums.find(target - num) != nums.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        nums.insert(num);
    }
    cout << "No" << endl;
    return 0;
}