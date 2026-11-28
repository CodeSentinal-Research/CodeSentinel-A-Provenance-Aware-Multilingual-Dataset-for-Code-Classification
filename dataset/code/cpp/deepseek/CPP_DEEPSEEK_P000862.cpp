#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    for (int num : nums) {
        if (freq[num] == 1) {
            return num;
        }
    }
    return 0; 
}

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << singleNumber(nums);
    return 0;
}
This code is designed to take an array of integers and return the unique element. It uses a hash map (unordered_map) to count the frequency of each number in the array. Then it iterates over the array again and returns the number whose frequency is 1.

Please make sure to input the number of elements and the elements themselves. For instance, if you input 6 for the number of elements and 1, 2, 3, 4, 1, 2, you should get 3 as the output.