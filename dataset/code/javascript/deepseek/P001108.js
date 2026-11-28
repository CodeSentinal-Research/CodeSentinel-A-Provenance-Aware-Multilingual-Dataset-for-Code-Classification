Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [N, M, Q] = rl.question('Enter vertices, edges and queries: ').split(' ').map(item => parseInt(item));

let graph = Array.from(Array(N), (val, i) => i);
let isConnected = Array(N).fill(false);

const getParent = (x, p) => {
    if (p[x] == x) return x;
    return getParent(p[x], p);
}

const union = (x, y, p, rank) => {
    x = getParent(x, p);
    y = getParent(y, p);

    if (x == y) return false;

    if (rank[x] < rank[y]) {
        p[x] = y;
        rank[y] += rank[x];
    } else {
        p[y] = x;
        rank[x] += rank[y];
    }

    return true;
}

for (let i = 0; i < M; i++) {
    let [x, y] = rl.question('Enter edge ' + (i + 1) + ' (' + N + '): ').split(' ').map(item => parseInt(item) - 1);
    graph[y] = x;
    isConnected[x] = union(x, y, graph, isConnected);
}

for (let i = 0; i < Q; i++) {
    let [x, y] = rl.question('Enter query ' + (i + 1) + ' (' + N + '): ').split(' ').map(item => parseInt(item) - 1);
    console.log((getParent(x, graph) == getParent(y, graph)) ? 'YES' : 'NO');
}

rl.close();

This code reads the input, creates a graph and then performs reachability queries. The graph is represented as an adjacency list and a union-find data structure is used to detect cycles. If the graph contains a cycle, there will not be a path from any vertex to any other vertex.