#include <iostream>
#include <vector>

using namespace std;

void printSubsequences(vector<int>& arr, vector<int>& temp, int index) {
    if (index == arr.size()) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }

    temp.push_back(arr[index]);
    printSubsequences(arr, temp, index + 1);

    temp.pop_back();
    printSubsequences(arr, temp, index + 1);
}

int main() {
    int arr[] = {1, 3, 5};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> temp;
    printSubsequences(nums, temp, 0);
    return 0;
}
This code will generate all the possible subsequences of the array. It uses recursion to generate the subsequences. The `printSubsequences` function takes an array, a temporary array to hold the current subsequence, and the index of the current element. It recursively includes the current element in the subsequences and the recursive calls for the next element. After that, it removes the current element from the subsequences and the recursive calls for the next element. This process is repeated until all elements of the array have been processed.