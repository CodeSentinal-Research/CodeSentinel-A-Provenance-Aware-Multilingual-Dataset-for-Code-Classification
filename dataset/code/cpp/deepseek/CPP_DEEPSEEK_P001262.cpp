#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> course(n);
    for (int i = 0; i < n; i++) {
        cin >> course[i].second >> course[i].first;
    }

    sort(course.begin(), course.end(), greater<pair<int, int>>());
    
    int maxDeadline = 0;
    int maxCourses = 0;
    for (int i = 0; i < n; i++) {
        if (course[i].second > maxDeadline) {
            maxDeadline = course[i].second;
            maxCourses++;
        }
    }
    
    cout << maxCourses << endl;
    
    return 0;
}
This C++ program uses a priority queue to sort the courses based on their deadlines in descending order. It iterates through the sorted courses, and for each course, if its duration is larger than the current maxDeadline (which is the end of the current course), it updates the maxDeadline and increments the maxCourses. At the end, it prints the maximum number of courses that can be completed.