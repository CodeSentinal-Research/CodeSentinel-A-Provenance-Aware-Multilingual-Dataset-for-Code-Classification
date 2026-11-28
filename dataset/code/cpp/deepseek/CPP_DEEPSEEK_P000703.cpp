#include <iostream>
using namespace std;

bool isPalindrome(int index, int arr[], int n) {
    if (index >= n / 2) {
        return true;
    }

    if (arr[index] != arr[n - index - 1]) {
        return false;
    }

    return isPalindrome(index + 1, arr, n);
}

int main() {
    int arr[] = {1, 2, 3, 2, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    if (isPalindrome(0, arr, n)) {
        cout << "Array is a palindrome." << endl;
    } else {
        cout << "Array is not a palindrome." << endl;
    }

    return 0;
}
This program defines a function `isPalindrome` that checks if an array is a palindrome using recursion. The function takes an index into the array, an array itself, and the size of the array as arguments. The base case of the recursion is when the index is equal to the size of the array divided by 2, in which case the array is a palindrome. If the current element (`arr[index]`) is not equal to the corresponding element from the end (`arr[n - index - 1]`), the function returns false, indicating that the array is not a palindrome. Otherwise, the function recursively calls itself with the next index.

The `main` function is the entry point of the program. It sets up an example array and calls the `isPalindrome` function. If the array is a palindrome, it prints "Array is a palindrome." Otherwise, it prints "Array is not a palindrome."