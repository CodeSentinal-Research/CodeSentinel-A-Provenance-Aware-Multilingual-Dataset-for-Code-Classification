#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class UniqueNumberQueue {
private:
    queue<int> q;
    unordered_set<int> seen;

public:
    void add(int value) {
        if (seen.find(value) == seen.end()) {
            q.push(value);
            seen[value] = true;
        }
    }

    int showFirstUnique() {
        while (!q.empty()) {
            int first = q.front();
            if (seen.find(first) == seen.end()) {
                return first;
            }
            q.pop();
        }
        return -1;
    }
};

int main() {
    UniqueNumberQueue queue;
    int n, value;
    char op;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        queue.add(value);
    }
    cin >> op;
    while (op != 'e') {
        if (op == 'a') {
            cin >> value;
            queue.add(value);
        } else {
            cout << queue.showFirstUnique() << endl;
        }
        cin >> op;
    }
    return 0;
}