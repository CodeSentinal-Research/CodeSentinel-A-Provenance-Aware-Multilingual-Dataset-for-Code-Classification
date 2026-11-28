Here is the code:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    unordered_set<int> distinct;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        distinct.insert(arr[i]);
    }

    for(int i = 0; i < Q; i++) {
        int index, value;
        cin >> index >> value;

        arr[index] = value;
        distinct.erase(arr[index]);
        distinct.insert(value);

        cout << distinct.size() << "\n";
    }

    return 0;
}
This code first reads the number of elements and the number of queries, and then reads the initial array. For each query, it reads the index and new value, updates the array at the given index with the new value, and prints the number of distinct elements.