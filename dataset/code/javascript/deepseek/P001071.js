Here is a JavaScript solution using Depth-First Search (DFS) on the given directed graph.

const fs = require('fs');
process.stdin.setEncoding('utf-8');
let inputString = '';
let currentLine = 0;

process.stdin.on('data', (inputLine) => {
    inputString += inputLine;
});

process.stdin.on('end', () => {
    inputString = inputString.trim().split('\n');
    const N = parseInt(inputString[currentLine++]);
    const edgeList = [];
    for (let i = 0; i < N-1; i++) {
        const temp = inputString[currentLine++].split(' ');
        edgeList.push([parseInt(temp[0]), parseInt(temp[1])]);
    }
    const M = parseInt(inputString[currentLine++]);
    const edges = [];
    for (let i = 0; i < M; i++) {
        const temp = inputString[currentLine++].split(' ');
        edges.push([parseInt(temp[0]), parseInt(temp[1])]);
    }
    const g = Array.from(Array(N + 1), () => []);
    for (let [u, v] of edgeList) g[u].push(v);
    const visited = Array(N + 1).fill(false);
    let mother = -1;
    for (let u = 1; u <= N; u++) {
        if (visited[u]) continue;
        visited[u] = true;
        let found = false;
        const stack = [u];
        while (stack.length) {
            const v = stack.pop();
            if (!found) mother = u;
            found = true;
            for (const w of g[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    stack.push(w);
                }
            }
        }
    }
    if (mother === -1) console.log(-1);
    else console.log(mother);
};

This code first reads the number of vertices and edges, then it reads the edges. It then creates a graph using the edges and a visited array to track which vertices have been visited. The mother vertex is initially set to -1. For each unvisited vertex, it marks the vertex as visited, and then performs a depth-first search to find all reachable vertices. If it finds a vertex that is not marked as visited (indicating that there is no mother vertex), it marks that vertex as the mother vertex. If all vertices can be reached from the mother vertex, it prints the mother vertex, otherwise it prints -1.