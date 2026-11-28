#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<double> solve(vector<pair<int, int>>& cars) {
    int n = cars.size();
    vector<double> res(n, -1.0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty()) {
            int j = st.top();
            if (cars[i].second <= cars[j].second) { st.pop(); continue; }
            double t = (double)(cars[j].first - cars[i].first) / (cars[i].second - cars[j].second);
            if (res[j] == -1.0 || t <= res[j]) { res[i] = t; break; }
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> cars(n);
    for(int i = 0; i < n; i++) cin >> cars[i].first >> cars[i].second;
    vector<double> ans = solve(cars);
    for(double x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
