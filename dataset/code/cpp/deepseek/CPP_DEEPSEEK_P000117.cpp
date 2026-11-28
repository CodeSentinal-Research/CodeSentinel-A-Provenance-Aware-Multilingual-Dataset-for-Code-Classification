#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> nums;
    bool duplicates = false;

    while (n--) {
        int num;
        cin >> num;

        if (nums.find(num) != nums.end()) {
            duplicates = true;
            break;
        }

        nums.insert(num);
    }

    cout << (duplicates ? "Yes" : "No") << endl;

    return 0;
}
This C++ program uses the unordered_set data structure from the STL to solve the problem. The unordered_set automatically handles the uniqueness of elements. It's a hash-based data structure, so it's very fast and efficient.

The program first reads the number of elements n. Then it enters a loop, where it reads each number and checks if it exists in the set. If it does, it sets the duplicates flag to true and breaks out of the loop. If it doesn't find the number, it inserts the number into the set. Finally, it prints "Yes" if duplicates exist, otherwise "No".