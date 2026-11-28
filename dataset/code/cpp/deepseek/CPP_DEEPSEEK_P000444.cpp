#include <iostream>
using namespace std;

int findPeak(int arr[], int n){
    int peak = 0;
    for(int i=1; i<n-1; i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            peak = i;
        }
    }
    return peak;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int peak = findPeak(arr, n);
    cout << peak;
    return 0;
}