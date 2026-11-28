#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> asteroids(n);
    for(int i=0; i<n; i++) cin >> asteroids[i];
    stack<int> st;
    for(int ast : asteroids) {
        bool destroyed = false;
        while(!st.empty() && st.top() > 0 && ast < 0) {
            if(abs(st.top()) < abs(ast)) { st.pop(); }
            else if(abs(st.top()) == abs(ast)) { st.pop(); destroyed = true; break; }
            else { destroyed = true; break; }
        }
        if(!destroyed) st.push(ast);
    }
    vector<int> res;
    while(!st.empty()) { res.push_back(st.top()); st.pop(); }
    for(int i=res.size()-1; i>=0; i--) cout << res[i] << " ";
    cout << endl;
    return 0;
}
