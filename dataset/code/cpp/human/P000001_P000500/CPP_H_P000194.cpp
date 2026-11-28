// Intersection of two unsorted arrays

#include<bits/stdc++.h>
using namespace std;

void intersection(int arr1[] , int s1 , int arr2[] , int s2){
    unordered_set <int> set(arr2 , arr2 + s2);
    for(int i = 0 ; i < s1 ; i++){
        if(set.find(arr1[i]) != set.end()){
            cout << arr1[i] << " ";
        }
    }
}

int main(){
    int arr1[] = {10 , 30 , 40};
    int s1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {30 , 40};
    int s2 = sizeof(arr2)/sizeof(arr2[0]);
    intersection(arr1 , s1 , arr2 , s2);
    return 0;
}