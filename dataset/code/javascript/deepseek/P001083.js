function checkHamiltonianPath() {
    var N = parseInt(readline());
    var M = parseInt(readline());
    var graph = [];
    for(let i = 0; i < M; i++) {
        var edge = readline().split(' ').map(Number);
        graph[edge[0]-1] = graph[edge[0]-1] || [];
        graph[edge[0]-1].push(edge[1]-1);
        graph[edge[1]-1] = graph[edge[1]-1] || [];
        graph[edge[1]-1].push(edge[0]-1);
    }

    function dfs(node, visited) {
        visited[node] = true;
        if(visited.length === N + 1) {
            return true;
        }
        for(let neighbour of graph[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour, visited)) {
                    return true;
                }
            }
        }
        visited[node] = false;
        return false;
    }

    if(dfs(0, new Array(N).fill(false))) {
        print("YES");
    } else {
        print("NO");
    }
}

This is a JavaScript solution for the given problem. It uses a Depth-First Search (DFS) algorithm to find if a Hamiltonian path exists in the graph. The graph is represented as an adjacency list, where each vertex is identified by its index and the list of its neighbours. The DFS function is called recursively on all unvisited vertices, starting from the first vertex (0). If a path is found that visits every vertex exactly once, it returns true. If no such path is found, it returns false. The result is printed as "YES" or "NO" accordingly.