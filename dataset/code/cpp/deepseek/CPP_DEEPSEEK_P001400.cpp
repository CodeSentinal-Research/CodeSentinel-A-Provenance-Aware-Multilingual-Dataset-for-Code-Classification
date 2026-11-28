#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> b(M);
    for(int i = 0; i < M; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> diff;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff));
    for(int val : diff) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> uniqueInB;
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(uniqueInB));
    for(int val : uniqueInB) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}