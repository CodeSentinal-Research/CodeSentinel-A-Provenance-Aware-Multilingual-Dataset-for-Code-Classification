#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dist(n), speed(n);
    for (int i = 0; i < n; ++i) cin >> dist[i];
    for (int i = 0; i < n; ++i) cin >> speed[i];
    
    vector<double> time(n);
    for (int i = 0; i < n; ++i) {
        time[i] = (double)dist[i] / speed[i];
    }
    
    sort(time.begin(), time.end());
    
    int eliminated = 0;
    for (int i = 0; i < n; ++i) {
        if (time[i] > i) {
            eliminated++;
        } else {
            break;
        }
    }
    
    cout << eliminated << endl;
    return 0;
}
