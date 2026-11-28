//Problem 26:  Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
//perm[i] is divisible by i.
//i is divisible by perm[i].
//Given an integer n, return the number of the beautiful arrangements that you can construct.

//Example 1:
//Input: n = 2
//Output: 2
//Explanation: 
//The first beautiful arrangement is [1,2]:
  //  - perm[1] = 1 is divisible by i = 1
    //- perm[2] = 2 is divisible by i = 2
//The second beautiful arrangement is [2,1]:
  //  - perm[1] = 2 is divisible by i = 1
    //- i = 2 is divisible by perm[2] = 1

//Example 2:
//Input: n = 1
//Output: 1
//Constraints: 1 <= n <= 15

#include <stdio.h>
#include <stdbool.h>

int count = 0; // Global variable to store count of beautiful arrangements

// Backtracking function
void countArrangements(int n, int pos, bool visited[]) {
    if (pos > n) {
        count++; // Valid arrangement found
        return;
    }

    for (int num = 1; num <= n; num++) {
        if (!visited[num] && (num % pos == 0 || pos % num == 0)) {
            visited[num] = true; // Mark as used
            countArrangements(n, pos + 1, visited);
            visited[num] = false; // Backtrack
        }
    }
}

// Function to calculate the number of beautiful arrangements
int beautifulArrangements(int n) {
    count = 0; // Reset count
    bool visited[n + 1]; // Boolean array to track visited numbers
    for (int i = 1; i <= n; i++) visited[i] = false;
    
    countArrangements(n, 1, visited);
    return count;
}

int main() {
    int n;

    // Get user input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Compute and display result
    int result = beautifulArrangements(n);
    printf("Number of beautiful arrangements: %d\n", result);

    return 0;
}

//Output :

//Example 1:
//Enter the value of n: 2
//Number of beautiful arrangements: 2

//Example 2:
//Enter the value of n: 1
//Number of beautiful arrangements: 1