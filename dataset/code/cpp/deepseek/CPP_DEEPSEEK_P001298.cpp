Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i];
    }

    sort(projects.begin(), projects.end());

    int maxWeeks = 0;
    for (int i = n - 1; i >= 0; i--) {
        maxWeeks += projects[i];
        if (maxWeeks > n) {
            maxWeeks -= n;
        }
    }

    cout << maxWeeks;

    return 0;
}

This program first reads the number of projects from the input, then reads the required weeks for each project. The projects are sorted in ascending order. 

Then, it iterates over the sorted list of projects from the last one to the first one, adding the required weeks to the maximum number of weeks that can be worked. If the maximum number of weeks exceeds the total number of projects, it subtracts the excess number of projects from the maximum number of weeks.

Finally, it prints the maximum number of workable weeks.