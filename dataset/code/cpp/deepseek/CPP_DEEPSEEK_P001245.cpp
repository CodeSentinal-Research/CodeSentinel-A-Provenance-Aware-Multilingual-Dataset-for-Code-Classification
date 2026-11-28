#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> people(N);

    for (int i = 0; i < N; i++) {
        int h, k;
        cin >> h >> k;
        people[i] = make_pair(h, k);
    }

    sort(people.begin(), people.end());

    for (int i = 0; i < N; i++) {
        cout << people[i].second << " ";
   
        int maxHeight = -1;
        int maxCount = 0;
        for (int j = 0; j < N; j++) {
            if (people[j].first >= people[i].first && people[j].second > maxCount) {
                maxHeight = people[j].first;
                maxCount = people[j].second;
            }
        }
        if (maxHeight == -1) {
            cout << "-1" << endl;
        } else {
            cout << maxHeight << endl;
        }
    }

    return 0;
}