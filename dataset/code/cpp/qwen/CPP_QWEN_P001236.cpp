#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> balloons(n);
    for (int i = 0; i < n; ++i) {
        cin >> balloons[i].first >> balloons[i].second;
    }
    
    sort(balloons.begin(), balloons.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int arrows = 1;
    int end = balloons[0].second;
    
    for (int i = 1; i < n; ++i) {
        if (balloons[i].first > end) {
            arrows++;
            end = balloons[i].second;
        }
    }
    
    cout << arrows << endl;
    return 0;
}
