Here is the code to solve the Course Schedule Ordering problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int vertices, vector<pair<int, int>>& edges) {
    vector<int> graph[vertices];
    vector<int> indegree(vertices, 0);

    for (auto edge : edges) {
        graph[edge.second].push_back(edge.first);
        indegree[edge.first]++;
    }

    queue<int> q;
    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> sortedCourses;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        sortedCourses.push_back(current);

        for (auto neighbor : graph[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (sortedCourses.size() == vertices) {
        return sortedCourses;
    } else {
        return vector<int>();
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<pair<int, int>> edgesList;
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        edgesList.push_back(make_pair(from, to));
    }

    vector<int> sortedCourses = topologicalSort(vertices, edgesList);

    if (sortedCourses.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < sortedCourses.size(); i++) {
            cout << sortedCourses[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

This program uses a topological sort algorithm to order the courses. It first constructs a graph from the prerequisite pairs, and then performs a topological sort on this graph. If the graph is a valid topological sort, the program will print the courses in the order they can be completed, otherwise, it will print IMPOSSIBLE.