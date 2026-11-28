#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    vector<int> preorder(n);
    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    int root = preorder[0];
    s.push(root);
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(preorder[i] < root) {
            if(s.size() > 0) {
                return cout << "NO", 0;
            }
            cnt++;
        } else {
            while(s.size() > 0 && preorder[i] > s.top()) {
                s.pop();
            }
            s.push(preorder[i]);
        }
    }
    while(s.size() > 1) {
        s.pop();
    }
    if(cnt > 1) {
        return cout << "NO", 0;
    } else {
        return cout << "YES", 0;
    }
}