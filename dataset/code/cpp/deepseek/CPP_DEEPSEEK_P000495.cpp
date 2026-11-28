Here is the C++ code for the problem:

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int price;
        cin >> price;

        stack<int> s;
        s.push(price);

        int span = 1;

        while (!s.empty() && s.top() <= price) {
            s.pop();
            span++;
        }

        cout << span << endl;
    }

    return 0;
}

This program uses a stack to keep track of the prices. The stack is initialized with the current price. If the current price is less than the top of the stack, it means that the current price is less than the previous price, and we need to increase the span. We pop out the prices from the stack until the current price is greater than the popped price.

The time complexity for this program is O(n), where n is the number of queries. This is because we only process each price once.