#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class FrequencyStack {
public:
    void push(int x) {
        stk.push(x);
        mp[x]++;
    }

    int pop() {
        int val = stk.top();
        stk.pop();
        mp[val]--;
        return val;
    }

private:
    stack<int> stk;
    unordered_map<int, int> mp;
};

int main() {
    FrequencyStack fs;
    int Q;
    cin >> Q;
    while(Q--) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            fs.push(x);
        } else {
            cout << fs.pop() << endl;
        }
    }
    return 0;
}