Here is the C++ code for the problem:

#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
    int start, end;
};

bool compare(Meeting m1, Meeting m2) {
    return m1.end < m2.end;
}

int maxMeetings(Meeting arr[], int n) {
    sort(arr, arr+n, compare);

    int maxMeetings = 1;
    int end = arr[0].end;

    for(int i = 1; i < n; i++) {
        if(arr[i].start > end) {
            maxMeetings++;
            end = arr[i].end;
        }
    }

    return maxMeetings;
}

int main() {
    int n;
    cin >> n;

    Meeting arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].end;
    }

    cout << maxMeetings(arr, n);

    return 0;
}
This code first sorts the meetings based on their end times. Then, it iterates through the sorted array, and if the current meeting starts after the end time of the last meeting, it means a new meeting can be scheduled, so it increments the count of meetings and updates the end time of the last meeting.