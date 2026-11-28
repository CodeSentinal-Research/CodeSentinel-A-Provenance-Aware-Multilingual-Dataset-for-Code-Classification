Here is the JavaScript code to solve the problem:

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N, M;
let graph = {};

rl.on('line', (line) => {
    if (N === undefined) {
        [N, M] = line.split(' ').map(Number);
        graph = Array.from(Array(N), (_, i) => i);
    } else {
        const [a, b] = line.split(' ').map(Number);
        graph[a] = graph[a].concat(b);
        graph[b] = graph[b].concat(a);
    }

    if (--M === 0) {
        rl.close();
    }
});

rl.on('close', () => {
    const criticalConnections = findCriticalConnections(0, -1, []);
    const result = criticalConnections.length > 0 ? criticalConnections.join('\n') : 'NONE';
    console.log(result);
    process.exit();
});

function findCriticalConnections(start, parent, skip) {
    let connections = [];

    for (let i = 0; i < graph[start].length; i++) {
        let a = graph[start][i];
        let b = start;

        if (a === parent) continue;

        if (i === 1 && a === skip) continue;

        connections.push([start, a]);
    }

    connections.sort((a, b) => {
        if (graph[a[0]].indexOf(a[1]) - graph[a[0]].indexOf(a[0]) === 0) {
            return a[0] < b[0] ? -1 : 1;
        } else if (graph[b[0]].indexOf(b[1]) - graph[b[0]].indexOf(b[0]) === 0) {
            return a[0] < b[0] ? 1 : -1;
        } else {
            return graph[a[0]].indexOf(a[1]) - graph[a[0]].indexOf(b[1]);
        }
    });

    let criticals = [];

    for (let i = 0; i < connections.length; i++) {
        let a = connections[i][0];
        let b = connections[i][1];

        graph[a] = graph[a].filter(x => x !== b);
        graph[b] = graph[b].filter(x => x !== a);

        if (isConnected(a, b)) {
            criticals.push(connections[i]);
        } else {
            graph[a] = [b];
            graph[b] = [a];
        }
    }

    return criticals;
}

function isConnected(a, b) {
    const visited = Array.from(Array(N), () => false);

    dfs(a, b, visited);

    return visited[b];
}

function dfs(a, b, visited) {
    visited[a] = true;

    if (a !== b && visited[b]) {
        return true;
    }

    for (let i = 0; i < graph[a].length; i++) {
        let c = graph[a][i];

        if (!visited[c] && dfs(c, b, visited)) {
            return true;
        }
    }

    return false;
}

This code reads the input from the standard input, and then processes the input line by line. It builds a graph using adjacency list representation. It finds all critical connections and prints them in lexicographical order if there are any. If there are no critical connections, it prints "NONE".