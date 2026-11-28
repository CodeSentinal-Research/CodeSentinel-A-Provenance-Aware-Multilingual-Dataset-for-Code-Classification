#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<pair<int, int>, int> m;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        int even = 0, odd = 0;

        for (int j = i; j < n; j++) {
            if (arr[j] % 2 == 0)
                even++;
            else
                odd++;

            if (even == odd) {
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    m[make_pair(i, j)] = max_len;
                }
            }
        }
    }

    int start, end;
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second == max_len) {
            start = i->first.first;
            end = i->first.second;
            break;
        }
    }

    cout << max_len;

    return 0;
}