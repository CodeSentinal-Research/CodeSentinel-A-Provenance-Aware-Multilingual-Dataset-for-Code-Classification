#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> nums;
    bool duplicate = false;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(nums.find(num) != nums.end()) {
            duplicate = true;
        } else {
            nums.insert(num);
        }
    }
    if(duplicate) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}