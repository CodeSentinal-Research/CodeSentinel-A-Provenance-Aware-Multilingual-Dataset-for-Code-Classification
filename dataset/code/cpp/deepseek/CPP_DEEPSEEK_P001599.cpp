#include <iostream>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    int* arr = new int[N];
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int L, R;
    for(int i = 0; i < Q; i++) {
        cin >> L >> R;
        int count = 0;
        for(int j = L-1; j <= R-1; j++)
            if(arr[j] % K == 0)
                count++;
        cout << count << endl;
    }

    delete [] arr;
    return 0;
}