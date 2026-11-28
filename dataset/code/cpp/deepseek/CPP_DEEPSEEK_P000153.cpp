Here's the code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rearrange(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        if(arr[start] > 0 && arr[end] < 0) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        else if(arr[start] > 0) {
            start++;
        }
        else if(arr[end] < 0) {
            end--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rearrange(arr);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
This program reads an integer N followed by N integers. It then rearranges the positive and negative numbers in the array in such a way that the positive numbers appear alternately to the left of the array and the negative numbers appear alternately to the right.