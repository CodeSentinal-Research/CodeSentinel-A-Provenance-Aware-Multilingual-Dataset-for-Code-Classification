#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void readInput(int rows, int cols, vector<vector<int>> &matrix) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int kadane(vector<int> &nums) {
    int maxSum = INT_MIN, sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(sum > maxSum) {
            maxSum = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    readInput(rows, cols, matrix);
    
    int maxSum = INT_MIN;
    
    for(int left = 0; left < cols; left++) {
        vector<int> nums(rows);
        for(int right = left; right < cols; right++) {
            for(int i = 0; i < rows; i++) {
                nums[i] += matrix[i][right];
            }
            int sum = kadane(nums);
            maxSum = max(sum, maxSum);
        }
    }
    
    cout << maxSum << endl;
    
    return 0;
}