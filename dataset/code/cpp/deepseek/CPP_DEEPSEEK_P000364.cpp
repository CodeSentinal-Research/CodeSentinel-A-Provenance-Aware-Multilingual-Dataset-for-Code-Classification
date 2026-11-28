Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        int found = 0;
        for(int j = 0; j < N; j++) {
            if(arr[j] == query) {
                found = 1;
                break;
            }
        }
        if(found == 1) {
            cout << "Found" << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}

This program reads the size of the array and then the array values, followed by the number of queries. For each query, it performs a linear search to find the query value in the array. If the query value is found, it outputs "Found"; otherwise, it outputs "Not Found".