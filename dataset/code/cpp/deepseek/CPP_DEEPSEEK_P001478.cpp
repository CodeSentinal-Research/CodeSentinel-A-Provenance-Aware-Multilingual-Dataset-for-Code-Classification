#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Interval> first(N);
    for (int i = 0; i < N; i++) {
        cin >> first[i].start >> first[i].end;
    }

    vector<Interval> second(M);
    for (int i = 0; i < M; i++) {
        cin >> second[i].start >> second[i].end;
    }

    sort(first.begin(), first.end(), [](Interval a, Interval b) { return a.start < b.start; });
    sort(second.begin(), second.end(), [](Interval a, Interval b) { return a.start < b.start; });

    vector<Interval> result;
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (first[i].end < second[j].start) {
            i++;
        } else if (first[i].start > second[j].end) {
            j++;
        } else {
            result.push_back(Interval {
                max(first[i].start, second[j].start),
                min(first[i].end, second[j].end)
            });
            i++;
            j++;
        }
    }

    if (result.empty()) {
        cout << "No Intervals" << endl;
    } else {
        for (Interval interval : result) {
            cout << interval.start << " " << interval.end << endl;
        }
    }

    return 0;
}
This program reads two lists of intervals, sorts them, and then finds and prints all intersections between the two lists. The program uses the `sort` function from the STL and a lambda function to compare the start times of the intervals.