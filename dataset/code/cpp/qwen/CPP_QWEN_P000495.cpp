#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class StockSpanner {
    stack<pair<int, int>> st;
public:
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
int main() {
    int q; cin >> q;
    StockSpanner ss;
    while(q--) {
        int price; cin >> price;
        cout << ss.next(price) << endl;
    }
    return 0;
}
