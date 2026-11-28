Here is the C++ code for the problem:

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }
    if (nums.size() * 2 < n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}

This program first reads the number of integers and the integers themselves. It then counts the unique integers in the array using a `unordered_set`. If the number of unique integers is less than the number of integers divided by 2 (since we need to divide the array into pairs), it prints "NO". Otherwise, it prints "YES".