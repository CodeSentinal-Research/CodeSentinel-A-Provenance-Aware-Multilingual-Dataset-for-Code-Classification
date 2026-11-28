Here is a simple JavaScript solution using a graph traversal approach:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let graph = {};

rl.on('line', (line) => {
    let [node1, node2] = line.split(' ');
    if (!graph[node1]) graph[node1] = [];
    graph[node1].push(node2);
    if (!graph[node2]) graph[node2] = [];
    graph[node2].push(node1);
})

.on('close', () => {
    rl.close();
    let [N, M, S, K] = rl.line().split(' ').map(Number);
    console.log(countVertices(N, M, S, K));
})

function countVertices(N, M, S, K) {
    let visited = {};
    return dfs(S, K, visited).reduce((a, v) => a + countNodes(v, visited), 0);
}

function dfs(node, K, visited) {
    if (visited[node]) return [];
    visited[node] = true;
    let arr = [node];
    for (let neighbor of graph[node])
        arr.push(...dfs(neighbor, K, visited));
    return arr;
}

function countNodes(node, visited) {
    if (visited[node]) return 0;
    visited[node] = true;
    return 1 + dfs(node, K, visited).reduce((a, v) => a + countNodes(v, visited), 0);
}

This code reads the graph from input, and then uses depth-first search (DFS) to find all nodes at distance K. The visited objects keep track of the nodes that have been visited. The countNodes function is used to count the number of nodes at distance K, and the countVertices function is used to count the number of vertices at distance K.