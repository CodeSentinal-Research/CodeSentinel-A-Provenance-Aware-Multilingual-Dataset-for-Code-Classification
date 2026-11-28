Here is the code for the problem:

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    unordered_set<int> distinct;
    for (int i = 0; i < N && K > 0; i++) {
        if (distinct.find(A[i]) == distinct.end()) {
            distinct.insert(A[i]);
        } else {
            K--;
        }
    }
    cout << distinct.size() - (K > 0) << '\n';
    return 0;
}
This program first reads the number of elements (N) and the number of removals (K). It then reads the elements themselves. The program then uses an unordered_set to keep track of the distinct elements in the array. For each element in the array, if it's not in the set (i.e., it's not a duplicate), it's added to the set. If it's already in the set, K is decremented. Finally, the size of the set minus the K value (if K > 0, this means there are still elements that haven't been removed) is printed.