#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return (a.finish < b.finish);
}

int activitySelection(Activity activities[], int n) {
    sort(activities, activities+n, compare);

    int i = 0;
    int count = 0;
    int current_finish = -1;

    while (i < n) {
        if (activities[i].start > current_finish) {
            count++;
            current_finish = activities[i].finish;
        }
        i++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    Activity activities[n];

    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    cout << activitySelection(activities, n) << endl;

    return 0;
}