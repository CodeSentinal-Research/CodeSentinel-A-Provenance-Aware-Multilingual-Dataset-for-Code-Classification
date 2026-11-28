#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distributeCookies(vector<int>& cookies, int k, int index, vector<int>& children) {
    if (index == cookies.size()) {
        return *max_element(children.begin(), children.end());
    }
    
    int minUnfairness = INT_MAX;
    for (int i = 0; i < k; ++i) {
        children[i] += cookies[index];
        minUnfairness = min(minUnfairness, distributeCookies(cookies, k, index + 1, children));
        children[i] -= cookies[index];
        
        // Optimization: if child is empty, don't try other empty children
        if (children[i] == 0) break;
    }
    return minUnfairness;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cookies(n);
    for (int i = 0; i < n; ++i) cin >> cookies[i];
    
    vector<int> children(k, 0);
    cout << distributeCookies(cookies, k, 0, children) << endl;
    return 0;
}
