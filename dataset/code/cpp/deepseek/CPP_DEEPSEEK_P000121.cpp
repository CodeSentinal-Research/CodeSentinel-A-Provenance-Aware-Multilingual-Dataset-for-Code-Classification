#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int majority = findMajority(arr, n);
    cout << majority;

    return 0;
}

int findMajority(int arr[], int size) {
    int count = 1;
    int majority = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] == majority)
            count++;
        else if(count == 0) {
            majority = arr[i];
            count = 1;
        } else {
            count--;
        }
    }

    count = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] == majority)
            count++;
    }

    if(count > size/2)
        return majority;
    else
        return -1; 
}
This code includes the necessary headers, the main function, and a helper function to find the majority element. The main function reads in the size of the array, allocates memory for the array, and reads the elements. It then calls the findMajority function to find and print the majority element. If no majority element is found, it returns -1.