Here is the complete C++ code:

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> d;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        while(!d.empty() && d.front() < num) {
            d.pop_front();
        }
        d.push_back(num);
        if(d.size() > k) {
            d.pop_front();
        }
    }
    int minDiff = INT_MAX;
    while(!d.empty()) {
        int maxNum = d.back();
        d.pop_back();
        if(d.empty()) {
            minDiff = min(minDiff, maxNum);
        } else {
            minDiff = min(minDiff, maxNum - d.front());
        }
        if(!d.empty()) {
            d.pop_front();
        }
    }
    cout << minDiff << endl;
    return 0;
}
This program uses a deque to store the input numbers. The deque is used because it allows for efficient popping and pushing of elements at both ends (max and min). The while loop pops the front of the deque if it's not the max in the current window, and pushes the next number onto the back. If the size of the deque exceeds k, the front of the deque is popped. In the end, the min difference is found by popping the front of the deque and finding the difference with the max in the current window, and repeating this process until the deque is empty.