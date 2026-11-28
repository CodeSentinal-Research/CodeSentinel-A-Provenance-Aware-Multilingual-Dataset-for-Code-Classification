#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for(int i=0; i<size-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    int q, x;
    char c;
    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> c >> x;
        switch(c) {
            case 'p':
                s.push(x);
                break;
            case 'o':
                s.pop();
                break;
            case 't':
                cout << s.top() << "\n";
                break;
            case 'e':
                if(s.empty())
                    cout << "true\n";
                else
                    cout << "false\n";
                break;
        }
    }
    return 0;
}