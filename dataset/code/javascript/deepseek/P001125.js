let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let lines = [];

rl.on('line', function(line) {
    lines.push(parseInt(line));
});

rl.on('close', function() {
    solve(lines[0], lines[1], lines[2], lines.slice(3));
});

function solve(N, M, S, MAP) {
    let parent = Array.from({length: N + 1}, (_, i) => i);
    let delay = Array.from({length: N + 1}, () => Infinity);
    delay[S] = 0;

    for (let i = 0; i < M; i++) {
        let u = MAP[i * 3], v = MAP[i * 3 + 1], w = MAP[i * 3 + 2];
        if (delay[v] > delay[u] + w) {
            delay[v] = delay[u] + w;
            parent[v] = u;
        }
    }

    for (let i = 0; i < N; i++) {
        let u = parent[i + 1], v = i, w;
        if (delay[v] > delay[u] + w) {
            console.log(-1);
            return;
        }
    }

    console.log(delay.slice(1).join(' '));
}
In this code, we use a variation of Dijkstra's algorithm for finding the shortest paths in a graph. We initialize the delay from the source to all other nodes as infinity and from the source to the target as 0. Then we relax all edges. If the new computed delay is smaller than the previous one, we update the delay. Finally, we print the delays. If any node cannot be reached, we print -1.