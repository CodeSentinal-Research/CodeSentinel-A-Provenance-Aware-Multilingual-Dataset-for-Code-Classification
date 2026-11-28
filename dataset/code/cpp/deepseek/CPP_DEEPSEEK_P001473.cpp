Here is the code:

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int closest = INT_MAX;
    sort(arr, arr+n);
    
    for(int i=0; i<n-2; i++) {
        int l = i+1;
        int r = n-1;
        while(l < r) {
            if(abs(target - closest) > abs(target - (arr[i] + arr[l] + arr[r]))) {
                closest = arr[i] + arr[l] + arr[r];
            }
            if(arr[i] + arr[l] + arr[r] < target) {
                l++;
            } else if(arr[i] + arr[l] + arr[r] > target) {
                r--;
            } else {
                closest = arr[i] + arr[l] + arr[r];
                break;
            }
        }
    }
    
    cout << closest;
    return 0;
}

This program works by first sorting the array. Then, for each pair of numbers in the array, it uses a two-pointer approach to find the closest sum to the target. The pointers l and r are moved accordingly in each iteration. The closest sum is updated if a new sum is found that is closer to the target than the current closest sum. The algorithm breaks if the sum of the three numbers is equal to the target or if the sum is greater than the target.