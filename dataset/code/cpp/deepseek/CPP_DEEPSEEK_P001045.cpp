#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> heap1(n);
    vector<int> heap2(m);
    for (int i = 0; i < n; i++) {
        cin >> heap1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> heap2[i];
    }
    bool identical = true;
    if (n != m) {
        identical = false;
    } else {
        for (int i = 0; i < n; i++) {
            if (heap1[i] != heap2[i]) {
                identical = false;
                break;
            }
        }
    }
    if (identical) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}