Here is the code for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int goodPairs = 0;
    unordered_map<int, int> numCount;

    for (int num : nums) {
        goodPairs += numCount[num];
        numCount[num]++;
    }

    cout << goodPairs << endl;

    return 0;
}
In this code, we are first reading the size of the array from the input. Then, we read the array elements. We use an unordered map `numCount` to count the frequency of each number in the array. For each number in the array, we add the count of the number in `numCount` to the total good pairs. Finally, we print the total good pairs.