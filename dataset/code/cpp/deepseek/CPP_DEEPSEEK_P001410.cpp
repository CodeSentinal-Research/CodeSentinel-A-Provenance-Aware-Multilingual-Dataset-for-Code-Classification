Here is the C++ code:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int badPairs = 0;
    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        if(freq.find(nums[i] - 1) != freq.end()) {
            badPairs += freq[nums[i] - 1];
        }
        freq[nums[i]]++;
    }

    cout << badPairs << endl;

    return 0;
}
This program reads an integer array of size N from the input, and counts the number of bad pairs. A bad pair is a pair (i, j) such that i < j and j - i ≠ nums[j] - nums[i].

This program uses an unordered_map to keep track of the frequency of each number in the array. It increments the count of the frequency of nums[i] by 1 and increments the count of the frequency of nums[i] - 1 (which represents a bad pair) by the current count of nums[i] (which represents the number of bad pairs).