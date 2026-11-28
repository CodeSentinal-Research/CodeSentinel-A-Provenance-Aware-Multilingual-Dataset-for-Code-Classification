#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int q;
    cin >> q;
    cin.ignore();

    stack<string> history;
    queue<string> forwardQueue;

    string homepage;
    getline(cin, homepage);
    history.push(homepage);

    for (int i = 0; i < q; i++) {
        string operation;
        getline(cin, operation);

        if (operation.find("back") != string::npos) {
            if (!history.empty()) {
                history.pop();
                if (!forwardQueue.empty()) {
                    string forwardUrl = forwardQueue.front();
                    forwardQueue.pop();
                    history.push(forwardUrl);
                }
            }
        } else if (operation.find("forward") != string::npos) {
            if (!forwardQueue.empty()) {
                string forwardUrl = forwardQueue.front();
                forwardQueue.pop();
                history.push(forwardUrl);
            }
        } else {
            if (history.size() > 1) {
                string prevUrl = history.top();
                history.pop();
                forwardQueue.push(prevUrl);
            }
            string newUrl = operation;
            history.push(newUrl);
        }

        if (!history.empty()) {
            cout << history.top() << endl;
        }
    }

    return 0;
}