#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> m;
    deque<int> d;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(m.find(arr[i]) == m.end()) {
            m[arr[i]] = i;
            d.push_back(arr[i]);
        } else {
            m[arr[i]] = i;
        }

        while(d.size() > k) {
            if(m[d.front()] == i - k) {
                m.erase(d.front());
                d.pop_front();
            } else {
                break;
            }
        }

        if(d.size() == k) {
            ans += (i - k + 1);
        }
    }

    cout << ans << endl;

    return 0;
}