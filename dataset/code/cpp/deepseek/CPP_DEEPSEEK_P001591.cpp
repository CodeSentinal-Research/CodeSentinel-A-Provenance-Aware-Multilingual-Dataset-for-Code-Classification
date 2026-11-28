Here is the code:

#include <iostream>
using namespace std;

int main() {
    int N, Q, A;
    cin >> N;
    int* arr = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> A;
        arr[i] = A;
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> A >> A;
        cout << arr[A] << endl;
    }
    delete [] arr;
    return 0;
}

In this code, we first read the size of the array and the number of queries, then read the array itself. After that, we perform the sum query for each query and print the result.