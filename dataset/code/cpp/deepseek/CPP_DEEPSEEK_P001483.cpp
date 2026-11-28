Here is the code:

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> dq(n);
    for(int i = 0; i < n; i++) {
        cin >> dq[i];
    }
    int start = 0, max_ones = 0;
    deque<int> window(n);
    for(int end = 0; end < n; end++) {
        if(dq[end] == 1) {
            max_ones++;
        }
        window[end % n] = dq[end];
        while(max_ones - window.front() > k) {
            if(window[start % n] == 1) {
                max_ones--;
            }
            start++;
        }
        max_ones = max(max_ones, end - start + 1);
    }
    cout << max_ones << endl;
    return 0;
}

This code reads the binary array and the maximum number of zeros allowed as input. It then reads the binary array into a deque. The code then finds the maximum length of a subarray with at most k zeros turned to ones. The subarray is stored in a deque and the length of the subarray is updated as the deque moves. The code also handles the case where the end of the deque is reached and the length of the subarray is not yet updated. The final length is printed out.