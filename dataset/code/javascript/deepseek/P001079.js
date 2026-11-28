Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [n, m] = rl.question('').split(' ').map(x => parseInt(x));

let graph = new Array(n).fill(null).map((_, i) => ({
    from: [],
    to: [],
    value: Infinity
}));

for (let i = 0; i < m; i++) {
    let [u, v, w] = rl.question('').split(' ').map(x => parseInt(x) - 1);
    graph[u].from.push(v);
    graph[v].to.push(u);
    graph[u].value = Math.min(graph[u].value, w);
    graph[v].value = Math.min(graph[v].value, w);
}

function dfs(node, parent = -1) {
    for (let neighbour of graph[node].from) {
        if (neighbour !== parent) {
            graph[neighbour].value = Math.min(graph[neighbour].value, graph[node].value);
            dfs(neighbour, node);
        }
    }
}

let bridges = [];

for (let i = 0; i < n; i++) {
    if (graph[i].value < Infinity) {
        bridges.push(i);
    }
}

if (bridges.length === 0) {
    console.log('NONE');
} else {
    console.log(bridges.join(' '));
}

rl.close();

In this code, we first read the number of nodes and edges, then we read the edges and update the graph accordingly. After that, we perform a Depth-First Search (DFS) on the graph to find all bridges. If no bridges are found, we print 'NONE'. Otherwise, we print all the bridge edges in ascending order.