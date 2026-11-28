Here is the code for the problem:

#include <iostream>
using namespace std;

int countTrees(int n) {
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += countTrees(i - 1) * countTrees(n - i);
    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n < 1 || n > 19) {
        cout << "Invalid input";
        return 0;
    }
    cout << countTrees(n);
    return 0;
}
In this code, we use recursion to count the number of unique Binary Search Trees. The function countTrees(int n) calculates the number of unique Binary Search Trees for input n. If n is less than or equal to 1, we return 1 because there is only 1 unique Binary Search Tree.

Then for each number from 1 to n, we recursively calculate the number of unique Binary Search Trees for the left part (i - 1) and right part (n - i). The total number of unique Binary Search Trees for a given n is the product of these two counts.

In the main function, we handle the input and output. We first ask for the number of elements, then check if it is valid (between 1 and 19). Finally, we print the result.