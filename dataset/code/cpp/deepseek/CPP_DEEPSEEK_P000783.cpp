Here is the code:

#include <iostream>
using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int prefix[n+1] = {0};
    for(int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + arr[i] % 2;
    }
    for(int i=0; i<q; i++) {
        cin >> l >> r;
        cout << (prefix[r] - prefix[l-1]) << endl;
    }
    return 0;
}
This program reads an array of integers and multiple queries in the form of a range [L, R]. It then counts the number of even numbers within each range and prints the count. The program uses a prefix sum approach to calculate the count of even numbers in each range.