//Shortest Unsorted Continuous Subarray

#include <stdio.h>
#include <limits.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int left = 0, right = n-1;
    
    while(left < n-1 && arr[left] <= arr[left+1]){
        left++;
    }
    
    if(left == n-1){
        printf("0");
        return 0;
    }
    
    while(right > 0 && arr[right] >= arr[right-1]){
        right--;
    }
    
    int max = INT_MIN, min = INT_MAX;
    for(int i = left; i <= right; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }
    
    while(left > 0 && arr[left - 1] > min){
        left--;
    }
    
    while(right < n-1 && arr[right+1] < max){
        right++;
    }
    
    printf("%d", right - left + 1);
    return 0;
}