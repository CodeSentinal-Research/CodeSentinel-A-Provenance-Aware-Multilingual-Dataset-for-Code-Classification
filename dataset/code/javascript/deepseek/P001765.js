Here is a JavaScript solution for the given problem:

let fs = require('fs');
let readline = require('readline');

let input = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(input.next());

let tree = [];
let leafCounts = new Array(N).fill(0);

function dfs(node, depth) {
    if (tree[node].length === 0) {
        leafCounts[depth]++;
        return;
    }
    for (let i = 0; i < tree[node].length; i++) {
        dfs(tree[node][i], depth + 1);
    }
}

for (let i = 0; i < N; i++) {
    let line = input.next();
    tree[i] = JSON.parse(line);
}

dfs(0, 0);

let minCount = Math.min(...leafCounts);

let hasEqualCount = leafCounts.every(count => count === minCount);

console.log(hasEqualCount ? 'YES' : 'NO');

This script reads the input from the standard input, and processes it accordingly. The `readline` module is used to read the input lines, and the `fs` module is used to read the tree data. The tree data is parsed into an array and stored in the `tree` variable.

The `dfs` function performs a depth-first search of the tree, and counts the number of edges at each depth. The `leafCounts` array keeps track of the count of edges at each depth.

Finally, the script prints 'YES' if all paths have the same number of edges, and 'NO' otherwise.