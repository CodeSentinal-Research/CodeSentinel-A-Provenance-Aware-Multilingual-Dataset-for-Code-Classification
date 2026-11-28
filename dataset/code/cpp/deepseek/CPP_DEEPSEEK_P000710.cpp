#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printPermutations(vector<int> &nums, vector<int> &temp, int index) {
    if (index == nums.size()) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
            temp.push_back(nums[i]);
            printPermutations(nums, temp, index + 1);
            temp.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> temp;
    printPermutations(nums, temp, 0);
    
    return 0;
}