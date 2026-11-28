#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    int res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            int dist = dx * dx + dy * dy;

            for(int k = j + 1; k < N; k++) {
                dx = points[k].first - points[i].first;
                dy = points[k].second - points[i].second;
                int dist2 = dx * dx + dy * dy;

                if(dist == dist2) {
                    res++;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}