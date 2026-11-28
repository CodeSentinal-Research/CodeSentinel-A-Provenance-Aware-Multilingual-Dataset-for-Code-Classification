// Input:
//   - Number of nodes in the binary tree (1 <= N <= 2*10^5)
//   - Node values (Integer values between -10^9 and 10^9)
//   - K (Integer between -10^9 and 10^9)

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());
let nodes = rl.question().split(' ').map(Number);
let K = parseInt(rl.question());

let graph = new Map();
for (let i = 0; i < N - 1; i++) {
    let u = nodes[2 * i], v = nodes[2 * i + 1];
    if (!graph.has(u)) graph.set(u, []);
    if (!graph.has(v)) graph.set(v, []);
    graph.get(u).push(v);
    graph.get(v).push(u);
}

let res = 0;
let path = new Array(N + 1).fill(0);
path[0] = 1;

function dfs(u) {
    if (u === N) {
        let sum = 0;
        for (let i = 1; i <= N; i++) {
            sum += path[i];
        }
        if (sum === K) {
            res++;
        }
        return;
    }
    let children = graph.get(u);
    for (let i = 0; i < children.length; i++) {
        path[u + 1] = path[u] + 1;
        dfs(children[i]);
        path[u + 1] = 0;
    }
}

dfs(1);

console.log(res);