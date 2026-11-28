#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool canAllocate(const vector<int>& pages, int students, int maxPages) {
    int studentsUsed = 1;
    long long currentPages = 0;
    for (int p : pages) {
        if (currentPages + p > maxPages) {
            studentsUsed++;
            currentPages = p;
            if (studentsUsed > students) return false;
        } else {
            currentPages += p;
        }
    }
    return true;
}

int main() {
    int n, students;
    cin >> n >> students;
    vector<int> pages(n);
    for (int i = 0; i < n; ++i) cin >> pages[i];
    
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0LL);
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(pages, students, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
