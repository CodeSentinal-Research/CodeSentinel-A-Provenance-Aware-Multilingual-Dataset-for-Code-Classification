Here is the code for the problem:

// JavaScript code for the problem

let [N, M, Q] = process.argv.slice(2);
N = parseInt(N);
M = parseInt(M);
Q = parseInt(Q);

let graph = new Map();

for (let i = 0; i < M; i++) {
    let [u, v] = process.argv[3 + i].split(' ');
    u = parseInt(u);
    v = parseInt(v);

    if (!graph.has(u)) graph.set(u, []);
    if (!graph.has(v)) graph.set(v, []);

    graph.get(u).push(v);
    graph.get(v).push(u);
}

for (let i = 0; i < Q; i++) {
    let [u, v] = process.argv[3 + M + i].split(' ');
    u = parseInt(u);
    v = parseInt(v);

    if (graph.get(u).includes(v) || graph.get(v).includes(u))
        console.log('YES');
    else
        console.log('NO');
}

This code reads the graph edges from the command line arguments. It then creates a graph using a map where the key is a vertex and the value is an array of vertices connected to the vertex. For each query, it checks if the edge exists in the graph.

Please note that the input to the script is expected to be provided as command line arguments. The command line arguments are expected to be in the format `node script.js N M Q u1 v1 u2 v2 ...`, where `N`, `M`, and `Q` are the number of vertices, edges, and queries, respectively, and `u1 v1 u2 v2 ...` are the edges.