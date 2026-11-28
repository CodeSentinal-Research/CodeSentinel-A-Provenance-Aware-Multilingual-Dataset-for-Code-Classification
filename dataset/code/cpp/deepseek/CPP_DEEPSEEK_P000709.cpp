#include <iostream>
#include <algorithm>
using namespace std;

void swap(char *x, char *y) {
    char temp;
    temp = *x;
}

void permute(char *a, int l, int r) {
    int i;
    if (l == r)
        cout<<a<<endl;
    else {
        for (i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}

int main() {
    char s[9];
    cout << "Enter a string: ";
    cin >> s;
    int n = strlen(s);
    sort(s, s + n);
    permute(s, 0, n - 1);
    return 0;
}

This C++ code uses the Swap function to swap characters at two positions in an array, the Recursive Permute function to generate all permutations of a string, and the Main function to get user input and output. It also handles the sorting of the string and calls the permute function.