#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        int count = 0;
        for (int i = l; i <= r; ++i)
            if (a[i] == x)
                ++count;
        cout << count << '\n';
    }

    return 0;
}