Here is the JavaScript code for your problem. This code uses depth-first search to detect the cycle in the graph. The graph is represented as an adjacency list where each vertex is an array of its adjacent vertices.

let adjList = {};

function addEdge(v1, v2) {
    if (adjList[v1]) {
        adjList[v1].push(v2);
    } else {
        adjList[v1] = [v2];
    }
    if (adjList[v2]) {
        adjList[v2].push(v1);
    } else {
        adjList[v2] = [v1];
    }
}

function dfs(v, parent) {
    // Mark the current node as visited
    visited[v] = true;
  
    for (let i = 0; i < adjList[v].length; i++) {
        let adjV = adjList[v][i];
        
        // If adjacent node is not visited, then mark it as visited and recursively call the function
        if (!visited[adjV]) {
            if (dfs(adjV, v)) {
                return true;
            }
        } 
        // If adjacent node is already visited and is not the parent of current node, then graph contains cycle
        else if (adjV != parent) {
            return true;
        }
    }
    return false;
}

function solve(n, m, edges) {
    // Initialize visited array
    visited = {};
  
    // Add edges to the graph
    for (let i = 0; i < m; i++) {
        let v1 = edges[i][0];
        let v2 = edges[i][1];
        addEdge(v1, v2);
    }
  
    // Call dfs for each vertex to check if there is a cycle
    for (let v in adjList) {
        if (!visited[v] && dfs(v, null)) {
            console.log('YES');
            return;
        }
    }
    console.log('NO');
}

In this code, `visited` is an object that keeps track of the nodes that have been visited. The `dfs` function recursively checks for cycles in the graph starting from a given vertex. If a cycle is detected, it returns true; otherwise, it returns false. The `solve` function adds edges to the graph and calls the `dfs` function for each vertex to check for cycles.