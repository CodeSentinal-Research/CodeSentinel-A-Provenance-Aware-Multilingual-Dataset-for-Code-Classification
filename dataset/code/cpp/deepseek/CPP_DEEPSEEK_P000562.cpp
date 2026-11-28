#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int room = q.front();
        q.pop();

        for(int key : rooms[room]) {
            if(!visited[key]) {
                q.push(key);
                visited[key] = true;
            }
        }
    }

    for(bool v : visited) {
        if(!v) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> rooms(n);
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<int> r(m);
        for(int j = 0; j < m; j++) {
            cin >> r[j];
        }

        rooms[i] = r;
    }

    if(canVisitAllRooms(rooms)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}

This C++ solution implements a Breadth-First Search algorithm to solve the problem. It starts from room 0 and explores all the connected rooms. If there's a room with no keys (unvisited), it's not accessible. If it reaches the end of the list (all rooms have been visited), it returns true. If any room is not reachable, it returns false.