#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
            res[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main() {
    int n; cin >> n;
    vector<int> temperatures(n);
    for(int i=0; i<n; i++) cin >> temperatures[i];
    vector<int> res = dailyTemperatures(temperatures);
    for(int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
