#include <iostream>
#include <vector>

using namespace std;

int mergeSort(vector<int>& nums, int start, int end) {
    if (start >= end)
        return 0;
    
    int mid = start + (end - start) / 2;
    int leftCount = mergeSort(nums, start, mid);
    int rightCount = mergeSort(nums, mid + 1, end);
    
    int crossCount = merge(nums, start, mid, end);
    
    return leftCount + rightCount + crossCount;
}

int merge(vector<int>& nums, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);
    
    for (int i = 0; i < n1; i++)
        leftArray[i] = nums[start + i];
    
    for (int j = 0; j < n2; j++)
        rightArray[j] = nums[mid + j + 1];
    
    int i = 0, j = 0, k = start;
    
    int leftCount = 0, rightCount = 0, crossCount = 0;
    
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j])
            nums[k++] = leftArray[i++];
        else {
            nums[k++] = rightArray[j++];
            crossCount += (n1 - i);
        }
    }
    
    while (i < n1)
        nums[k++] = leftArray[i++];
    
    while (j < n2)
        nums[k++] = rightArray[j++];
    
    return crossCount;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    cout << mergeSort(nums, 0, n - 1) << "\n";
    
    return 0;
}