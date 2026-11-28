#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &st, int mid, int m, int n) {
    int sum = 0, count = 1;

    for(int i = 0; i < st.size(); i++) {
        if(st[i] > mid) return false;

        if(st[i] + sum > mid) {
            sum = st[i];
            count++;
        } else {
            sum += st[i];
        }
    }

    if(count > m) return false;

    return true;
}

int findPages(vector<int> &st, int m) {
    int s = 0, e = 0;

    for(int i = 0; i < st.size(); i++) {
        s = max(s, st[i]);
        e += st[i];
    }

    int ans = e;

    while(s <= e) {
        int mid = s + (e - s) / 2;

        if(isPossible(st, mid, m, st.size())) {
            e = mid - 1;
            ans = min(ans, mid);
        } else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> st(n);

    for(int i = 0; i < n; i++) {
        cin >> st[i];
    }

    cout << findPages(st, m);

    return 0;
}