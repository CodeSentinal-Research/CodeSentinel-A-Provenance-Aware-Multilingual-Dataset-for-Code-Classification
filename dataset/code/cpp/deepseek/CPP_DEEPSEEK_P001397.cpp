#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int R;
    cin >> R;

    vector<pair<int, int>> bricks;

    for (int i = 0; i < R; i++) {
        int num_bricks;
        cin >> num_bricks;
        vector<int> widths(num_bricks);
        for (int j = 0; j < num_bricks; j++) {
            cin >> widths[j];
        }
        bricks.push_back(make_pair(num_bricks, widths));
    }

    for (int i = 0; i < R; i++) {
        sort(bricks[i].second.begin(), bricks[i].second.end());
    }

    int min_bricks = R;

    for (int i = 0; i < R; i++) {
        int bricks_crossed = 0;
        for (int j = 0; j < bricks[i].first; j++) {
            if (j == 0 || bricks[i].second[j] < bricks[i].second[j - 1]) {
                bricks_crossed++;
            }
        }
        min_bricks = min(min_bricks, bricks_crossed);
    }

    cout << min_bricks << endl;

    return 0;
}