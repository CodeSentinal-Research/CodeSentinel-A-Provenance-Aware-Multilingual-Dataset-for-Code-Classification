Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> boxes(N);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }

    sort(boxes.begin(), boxes.end());

    int units = 0;
    for (int i = 0; i < N; i++) {
        if (units + boxes[i].first <= T) {
            units += boxes[i].first;
        } else {
            break;
        }
    }

    cout << units << endl;

    return 0;
}

This code first reads the number of boxes and the maximum truck capacity. Then it reads each box's number of boxes and units per box. The boxes are stored in a pair vector and sorted in ascending order. The code then iterates over the sorted boxes, adding the number of boxes to the total units until the total units exceed the truck capacity or the end of the boxes is reached. Finally, the code prints the maximum total units.