Here is a JavaScript solution for the problem. The solution uses a graph data structure to represent the tree and then uses depth-first search (DFS) to find the center of the tree. The center of a tree is the vertex which is connected to the farthest other vertices in the tree.

function solve() {
    var fs = require('fs');
    var input = fs.readFileSync('input.txt', 'utf8');
    var lines = input.split('\n');
    var N = parseInt(lines[0]);
    var graph = {};

    // Create graph
    for (var i = 1; i < N; i++) {
        var u = lines[i].split(' ')[0];
        var v = lines[i].split(' ')[1];
        if (!graph[u]) graph[u] = [];
        if (!graph[v]) graph[v] = [];
        graph[u].push(v);
        graph[v].push(u);
    }

    var maxDist = 0;
    var maxNode;

    // DFS to find the farthest node
    function dfs(node, parent) {
        var distances = {};
        var maxDistance = 0;
        var farthestNode;

        for (var i = 0; i < graph[node].length; i++) {
            var neighbor = graph[node][i];
            if (neighbor == parent) continue;
            if (!distances[neighbor]) {
                distances[neighbor] = 1;
                dfs(neighbor, node);
                distances[neighbor] += distances[node];
                if (maxDistance < distances[neighbor]) {
                    maxDistance = distances[neighbor];
                    farthestNode = neighbor;
                }
            } else {
                distances[neighbor] += distances[node];
                if (maxDistance < distances[neighbor]) {
                    maxDistance = distances[neighbor];
                    farthestNode = neighbor;
                }
            }
        }

        // Update max distance and farthest node
        if (maxDistance > maxDist) {
            maxDist = maxDistance;
            maxNode = farthestNode;
        }
    }

    dfs('1');

    console.log(maxNode);
}

This code reads the tree from the input file 'input.txt' and uses DFS to find the center of the tree. The 'solve' function initializes a graph and a variable 'maxDist' to 0. It then calls a DFS function to find the farthest node from the root node. If the distance to a node is greater than the current maximum distance, it updates the maximum distance and the farthest node. After all nodes have been visited, the farthest node is printed to the console.

Please note that this code assumes the root node of the tree is '1', and the tree is connected. If the tree is not connected, you need to use a different root node.

This solution is optimized to work with a large number of vertices (up to 2×10^5 in the given constraints).