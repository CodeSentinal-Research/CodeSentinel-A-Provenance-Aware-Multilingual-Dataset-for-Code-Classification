#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[20];
bool used[20];

void dfs(int idx, int k, vector<int> cur) {
    if (k == 0) {
        for (int i : cur) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < N; i++) {
        if (!used[i] && (cur.empty() || arr[i] > cur.back())) {
            used[i] = true;
            cur.push_back(arr[i]);
            dfs(i+1, k-1, cur);
            used[i] = false;
            cur.pop_back();
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    dfs(0, K, vector<int>());
    return 0;
}