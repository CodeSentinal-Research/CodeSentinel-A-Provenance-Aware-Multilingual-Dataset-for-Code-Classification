#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

struct Log {
    string id;
    int time;
};

vector<int> exclusive_time(vector<Log>& logs) {
    vector<int> result(logs.size(), 0);
    stack<pair<int, int>> stk;

    for (int i = 0; i < logs.size(); i++) {
        if (logs[i].id == "start") {
            if (!stk.empty()) {
                result[stk.top().first] += logs[i].time - stk.top().second;
            }
            stk.push({i, logs[i].time});
        } else {
            result[stk.top().first] += logs[i].time - stk.top().second + 1;
            stk.pop();
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<Log> logs(n);
    string s;
    getline(cin >> ws, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s);
        string id, time;
        ss >> id >> time;
        logs[i] = {id, stoi(time)};
    }

    vector<int> result = exclusive_time(logs);
    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
This code takes in the number of functions `n` and a list of logs as input. It then processes the logs and computes the exclusive time for each function. The result is printed out at the end.