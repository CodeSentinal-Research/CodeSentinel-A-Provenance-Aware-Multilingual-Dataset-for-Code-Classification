#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, diff;
    cin >> n >> diff;

    unordered_set<int> nums;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.insert(num);
    }

    int first, second;
    for (int i = 0; i < n; i++) {
        if (nums.find(num + diff) != nums.end()) {
            first = num + diff;
            second = num;
            break;
        }
    }

    if (first != 0) {
        cout << "Yes" << endl;
        cout << first << " " << second << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}