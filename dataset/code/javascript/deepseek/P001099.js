Here is the JavaScript code for the given problem:

let readline = require('readline');
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N, M;
rl.on('line', function(line) {
    [N, M] = line.split(' ').map(Number);
    let parent = Array(N + 1).fill(0).map((_, i) => i);
    let rank = Array(N + 1).fill(0);
    let cycle = false;

    function find(x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    function union(x, y) {
        let xr = find(x), yr = find(y);
        if (xr == yr) cycle = true;
        else parent[xr] = yr;
    }

    rl.on('line', function() {
        let [x, y] = rl.read().split(' ').map(Number);
        union(x, y);
    });

    rl.pause();

    if (cycle) rl.answer('YES\n');
    else rl.answer('NO\n');

    rl.close();
});

In this code, we use a simple Union-Find data structure with union and find operations. The union operation is used to merge two sets, and the find operation is used to find the representative of a set. The cycle flag is used to track if there is a cycle in the graph.

In the main part of the code, we read the graph edges from the input and union the edges in a loop. If a cycle is detected, we set the cycle flag to true and stop the process. If no cycle is detected, we print 'NO' to the output.

Please note that this code assumes that the input is a graph represented as a set of edges. The first line of the input contains the number of nodes and edges, and the remaining lines contain the edges in the format 'x y', where x and y are the node numbers.