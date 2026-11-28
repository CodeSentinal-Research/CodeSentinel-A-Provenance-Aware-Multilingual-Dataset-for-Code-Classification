#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> elevation(n);
    for(int i = 0; i < n; i++) {
        cin >> elevation[i];
    }

    int maxLeft = 0, maxRight = 0;
    int left = 0, right = n - 1;
    int trap = 0;

    while(left < right) {
        if(elevation[left] < elevation[right]) {
            if(elevation[left] > maxLeft) {
                maxLeft = elevation[left];
            } else {
                trap += maxLeft - elevation[left];
            }
            left++;
        } else {
            if(elevation[right] > maxRight) {
                maxRight = elevation[right];
            } else {
                trap += maxRight - elevation[right];
            }
            right--;
        }
    }

    cout << trap << endl;

    return 0;
}