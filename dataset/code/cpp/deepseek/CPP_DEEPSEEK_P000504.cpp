#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

struct Log {
    int id;
    bool isStart;
    int timestamp;
};

Log parseLog(string s) {
    stringstream ss(s);
    string id_str, isStart_str, timestamp_str;
    getline(ss, id_str, ':');
    getline(ss, isStart_str, ':');
    getline(ss, timestamp_str, ':');
    Log log = {stoi(id_str), isStart_str[0] == 's', stoi(timestamp_str)};
    return log;
}

vector<int> exclusiveTime(int n, vector<Log>& logs) {
    vector<int> result(n, 0);
    stack<pair<int, int>> st;
    for (Log& log : logs) {
        if (log.isStart) {
            if (!st.empty()) {
                result[st.top().first] += log.timestamp - st.top().second;
            }
            st.push({log.id, log.timestamp});
        } else {
            if (st.top().first == log.id) {
                result[log.id] += log.timestamp - st.top().second;
            }
            st.pop();
        }
    }
    while (!st.empty()) {
        if (!st.top().second) {
            result[st.top().first] += st.top().second;
        }
        st.pop();
    }
    return result;
}

int main() {
    int n = 3;
    vector<Log> logs = {
        {0, true, 1},
        {1, false, 2},
        {2, true, 3},
        {1, false, 4}
    };
    vector<int> result = exclusiveTime(n, logs);
    for (int time : result) {
        cout << time << " ";
    }
    return 0;
}