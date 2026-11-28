#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int num1 = -1, num2 = -1;
    int count1 = 0, count2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                if(arr[i]%2 == 0) {
                    if(count1%2 == 0) {
                        num1 = arr[i];
                        count1++;
                    } else {
                        num2 = arr[i];
                        count2++;
                    }
                } else {
                    if(count2%2 == 0) {
                        num1 = arr[i];
                        count1++;
                    } else {
                        num2 = arr[i];
                        count2++;
                    }
                }
            }
        }
    }
    if(num1 == -1 && num2 == -1) {
        cout << "No such pair";
    } else if(num1 == -1) {
        cout << num2 << " " << num2;
    } else if(num2 == -1) {
        cout << num1 << " " << num1;
    } else {
        cout << num1 << " " << num2;
    }
    return 0;
}
This C++ program reads the size of the array and the elements of the array, then it finds the two elements that occur odd number of times in the array. It also checks if the two elements are of the same type (even or odd) to decide which one to print. If no such pair exists, it prints "No such pair".