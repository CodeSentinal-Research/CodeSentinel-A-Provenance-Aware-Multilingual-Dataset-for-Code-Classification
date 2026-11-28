#include <iostream>
using namespace std;

int firstBadVersion(int n) {
    int start = 1, end = n;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    int n;
    cout << "Enter the number of versions: ";
    cin >> n;
    if (n < 1 || n > 2147483647) {
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << "First bad version is: " << firstBadVersion(n) << endl;
    return 0;
}