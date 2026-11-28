#include <iostream>
#include <list>
#include <string>
using namespace std;

class FrontMiddleBackQueue {
    list<int> l;
public:
    void pushFront(int val) { l.push_front(val); }
    void pushMiddle(int val) {
        auto it = l.begin(); advance(it, l.size() / 2);
        l.insert(it, val);
    }
    void pushBack(int val) { l.push_back(val); }
    int popFront() { if (l.empty()) return -1; int x = l.front(); l.pop_front(); return x; }
    int popMiddle() {
        if (l.empty()) return -1;
        auto it = l.begin(); advance(it, (l.size() - 1) / 2);
        int x = *it; l.erase(it); return x;
    }
    int popBack() { if (l.empty()) return -1; int x = l.back(); l.pop_back(); return x; }
};

int main() {
    int q_num; cin >> q_num;
    FrontMiddleBackQueue fmq;
    while(q_num--) {
        string op; cin >> op; int val;
        if(op == "pushFront" || op == "pushMiddle" || op == "pushBack") {
            cin >> val;
            if(op == "pushFront") fmq.pushFront(val);
            else if(op == "pushMiddle") fmq.pushMiddle(val);
            else fmq.pushBack(val);
        } else {
            if(op == "popFront") cout << fmq.popFront() << " ";
            else if(op == "popMiddle") cout << fmq.popMiddle() << " ";
            else if(op == "popBack") cout << fmq.popBack() << " ";
        }
    }
    cout << endl;
    return 0;
}
