#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr(m);
    for (int i = 0; i < m; ++i) cin >> arr[i];
    
    int patches = 0;
    long long reach = 1;
    int i = 0;
    
    while (reach <= n) {
        if (i < m && arr[i] <= reach) {
            reach += arr[i];
            i++;
        } else {
            reach += reach;
            patches++;
        }
    }
    
    cout << patches << endl;
    return 0;
}
