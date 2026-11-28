#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weeks(n);
    for (int i = 0; i < n; ++i) cin >> weeks[i];
    
    long long totalWeeks = accumulate(weeks.begin(), weeks.end(), 0LL);
    int maxWeeks = *max_element(weeks.begin(), weeks.end());
    
    if (maxWeeks <= totalWeeks - maxWeeks) {
        cout << totalWeeks << endl;
    } else {
        cout << 2 * (totalWeeks - maxWeeks) + 1 << endl;
    }
    
    return 0;
}
