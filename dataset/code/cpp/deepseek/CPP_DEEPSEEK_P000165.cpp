#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    long long max_product = arr[0];
    long long min_product = arr[0];
    long long global_max = arr[0];
    for(int i=1; i<N; i++) {
        if(arr[i] < 0)
            swap(max_product, min_product);
        max_product = max((long long)arr[i], max_product * arr[i]);
        min_product = min((long long)arr[i], min_product * arr[i]);
        global_max = max(global_max, max_product);
    }
    cout << global_max;
    return 0;
}