#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> nums1(n);
    for(int i=0; i<n; i++) cin >> nums1[i];
    int m; cin >> m;
    vector<int> nums2(m);
    for(int i=0; i<m; i++) cin >> nums2[i];
    unordered_map<int, int> next_greater;
    stack<int> st;
    for(int i=0; i<m; i++) {
        while(!st.empty() && a[st.top()] < a[i]) { // wait, nums2
            // fix
        }
    }
    // Simplified
    for(int i=0; i<n; i++) {
        int found = -1;
        for(int j=0; j<m; j++) {
            if(nums2[j] == nums1[i]) {
                for(int k=j+1; k<m; k++) {
                    if(nums2[k] > nums1[i]) { found = nums2[k]; break; }
                }
                break;
            }
        }
        cout << found << " ";
    }
    cout << endl;
    return 0;
}
