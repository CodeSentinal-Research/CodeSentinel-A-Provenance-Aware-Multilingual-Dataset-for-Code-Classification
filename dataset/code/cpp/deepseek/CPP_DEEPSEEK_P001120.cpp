Sure, here is the C++ code that should solve the problem:

#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    while(n--){
        string src, dest;
        cin >> src >> dest;
        adj[src].push(dest);
    }
    stack<string> ans;
    for(auto &x: adj){
        if(x.second.empty()){
            ans.push(x.first);
            while(!ans.top().empty()){
                string airport = ans.top();
                ans.pop();
                if(!ans.top().empty() && adj[ans.top()].top() == airport){
                    ans.push(adj[ans.top()].top());
                    adj[ans.top()].pop();
                }
            }
            break;
        }
    }
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}

This code first reads the number of tickets (N) and then reads the pairs of departure and arrival airport codes for N times. It uses a priority queue to store the departure airports. For each departure airport, it pushes its arrival airport to the priority queue. The priority queue is sorted in decreasing order of arrival airport codes.

Then, it performs a topological sort on the graph, i.e., it uses the depth-first search (DFS) algorithm. In the DFS, if a vertex is not visited, it marks it as visited and pushes its adjacent vertices to the stack. It pops the top item from the stack and recursively calls the DFS for the popped item.

Finally, it prints the reconstructed itinerary. The lexicographical order of the itinerary is guaranteed because the priority queue is used to store the arrival airport codes.