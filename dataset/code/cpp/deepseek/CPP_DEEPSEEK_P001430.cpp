#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        c[i] = a[i] == b[i] ? (i > 0 ? c[i-1] + 1 : 1) : 0;
    }
    
    for (int i = 0; i < N; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
This C++ code reads two permutations of integers from 1 to N from the standard input, computes an array where each element represents the number of common elements in the prefixes ending at that index, and prints the prefix common array.