Here is a simple implementation of a MinStack in C++. This implementation uses a standard stack to store elements, and a separate stack to store minimum elements. Push operation adds an element to both stacks. Pop operation removes from both stacks. Top operation returns the top element from both stacks. getMin operation returns the minimum element from the second stack.

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minS;
public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }

    void pop() {
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};

int main() {
    MinStack s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl; 
    cout << s.top() << endl; 
    s.pop();
    cout << s.getMin() << endl; 
    s.push(0);
    cout << s.getMin() << endl; 
    return 0;
}

This code will print:
1
1
2
0

This is because the minimum element in the stack is 0 when it's pushed. When the top element is popped, the minimum element is also popped. When the minimum element is popped, the top element is also popped.