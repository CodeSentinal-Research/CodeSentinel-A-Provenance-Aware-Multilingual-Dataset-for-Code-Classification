const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];
rl.on('line', (line) => {
    if (inputs.length === 0) {
        const [N, M] = line.split(' ').map(Number);
        inputs.push(N, M);
    } else if (inputs.length === 1) {
        const V = Number(line);
        inputs.push(V);
    } else {
        const [u, v] = line.split(' ').map(Number);
        inputs.push(u, v);
    }
    if (inputs.length === 3) {
        const graph = {};
        inputs.forEach((input, i) => {
            if (i % 2 === 0) {
                const u = input;
                graph[u] = [];
            } else {
                const v = input;
                graph[u].push(v);
                graph[v] = [];
            }
        });
        const neighbors = getNeighbors(graph, inputs[2]);
        console.log(neighbors.join(' '));
        inputs = [];
    }
}).on('close', () => {
    const [N, M] = inputs;
    const graph = {};
    inputs.forEach((input, i) => {
        if (i % 2 === 0) {
            const u = input;
            graph[u] = [];
        } else {
            const v = input;
            graph[u].push(v);
            graph[v] = [];
        }
    });
    const neighbors = getNeighbors(graph, inputs[0]);
    console.log(neighbors.join(' '));
    rl.close();
});

function getNeighbors(graph, v) {
    const neighbors = graph[v];
    neighbors.sort((a, b) => a - b);
    return neighbors;
}
This code reads the graph and the vertex from the standard input, then uses a recursive function to find the neighbors of the given vertex. The neighbors are printed to the standard output.