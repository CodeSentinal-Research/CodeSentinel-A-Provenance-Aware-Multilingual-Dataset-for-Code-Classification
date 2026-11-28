Here's the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [N, M] = rl.question('').split(' ').map(Number);

let adjacencyList = new Array(N + 1).fill().map(() => []);

for(let i = 0; i < M; i++) {
    let [u, v] = rl.question('').split(' ').map(Number);
    adjacencyList[u].push(v);
}

let zeroDegreeVertices = [];

for(let i = 1; i <= N; i++) {
    if(adjacencyList[i].length === 0) {
        zeroDegreeVertices.push(i);
    }
}

console.log(zeroDegreeVertices.length);

In this code, we read the number of vertices (N) and edges (M) from the input. Then we create an adjacency list of the graph. The adjacency list is an array where each index corresponds to a vertex and its value is an array of the vertices that the vertex is connected to.

We then iterate over each vertex and check if the adjacency list of the current vertex is empty. If it is, we add the vertex to the list of vertices with zero out-degree.

Finally, we print the number of vertices with zero out-degree.