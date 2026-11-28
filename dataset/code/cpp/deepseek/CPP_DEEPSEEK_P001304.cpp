Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<int> horizontal_cuts(R-1);
    for (int &cut: horizontal_cuts) {
        cin >> cut;
    }

    vector<int> vertical_cuts(C-1);
    for (int &cut: vertical_cuts) {
        cin >> cut;
    }

    sort(horizontal_cuts.begin(), horizontal_cuts.end());
    sort(vertical_cuts.begin(), vertical_cuts.end());

    int min_cost = horizontal_cuts[0] + vertical_cuts[0] + min(R, C);

    cout << min_cost << endl;

    return 0;
}

This code reads the number of rows and columns, the horizontal cut costs, and the vertical cut costs, and calculates the minimum total cutting cost. It uses the `sort` function to sort the cut costs in ascending order, and then uses the `min` function to select the minimum of the first two cuts. The minimum total cost is then printed out.