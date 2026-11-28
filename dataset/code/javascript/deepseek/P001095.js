Here is a JavaScript code for the problem. The code uses the Edmonds-Karp Algorithm, which is a famous algorithm used to solve the Maximum Flow problem. The algorithm finds the maximum flow in a graph.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = 0;

rl.on('line', (line) => {
    const inputs = line.split(' ').map(Number);
    const [N, M, S, T] = inputs;
    if (cases++ > 0) {
        console.log(`Case ${cases}: ${maxFlow(N, M, S, T, inputs)}`);
    }
});

function maxFlow(N, M, S, T, capacities) {
    let flow = 0;
    const edges = Array.from({length: N + 1}, () => new Array(N + 1).fill(-1));

    // Add the edges from S to each vertex
    for (let u = 1; u <= N; u++) {
        edges[u][S] = capacities[u - 1];
        edges[S][u] = 0;
    }

    // Add the edges to T
    for (let i = 0; i < M; i++) {
        const [u, v, cap] = capacities[i + 1];
        edges[u][v] = cap;
        edges[v][u] = 0;
    }

    // Use the Edmonds-Karp Algorithm
    let f;
    do {
        f = 0;
        let u = S;
        let t = T;
        let q = [u];
        const h = {
            [u]: 0,
        };
        while (q.length) {
            const u = q.pop();
            if (u === t) {
                f += capacities[h[u]];
            } else {
                for (let v in capacities) {
                    if (edges[u][v] > 0) {
                        if (!h[v] || capacities[h[u]] - edges[u][v] < capacities[h[v]] - edges[h[u]][v]) {
                            h[v] = u;
                            q.push(v);
                        }
                    }
                }
            }
        }
    } while (f < capacities[T]);

    return flow;
}

This script reads the number of vertices and edges, then reads the capacities of the edges. The capacities are then used to create a graph and find the maximum flow from the source to the sink.