Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findRightInterval(vector<vector<int>> intervals) {
    vector<int> result;
    for(auto& interval : intervals) {
        int min_end = interval[1];
        bool found = false;
        for(auto& other : intervals) {
            if(other[0] >= min_end) {
                result.push_back(other[1]);
                found = true;
                break;
            }
        }
        if(!found) {
            result.push_back(-1);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}};
    vector<int> result = findRightInterval(intervals);
    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}

In this code, we use two loops to iterate through each interval. In the first loop, we set the end of the current interval as the minimum end of any other interval. In the second loop, we check if the start of the current interval is greater than or equal to the minimum end. If it is, we have found a suitable interval and add its end to the result array. If no suitable interval is found, we add -1 to the result array.