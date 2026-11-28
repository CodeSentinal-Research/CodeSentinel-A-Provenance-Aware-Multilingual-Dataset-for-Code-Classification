Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', (line) => {
    input.push(line);
});

rl.on('close', () => {
    const [n] = input[0].split(' ').map(Number);
    const tree = Array.from(input.slice(1), (val) => val.split(' ').map(Number));
    console.log(houseRobber(tree, n));
});

function houseRobber(tree, n) {
    if (n === 0) return 0;

    let dp = new Array(n + 1).fill(-1);
    dp[0] = 0;
    dp[1] = tree[0];

    for (let i = 2; i <= n; i++) {
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + tree[i - 1]);
    }

    return dp[n];
}

In this code, we first read the number of nodes and the tree structure from the standard input. The tree structure is stored as a 2D array where each row represents a node and the value at the index corresponds to the value of the node.

Then we define the `houseRobber` function which uses dynamic programming to find the maximum sum without selecting both a node and its child. The dp array is used to store the maximum sum that can be obtained at each node. Initially, the maximum sum at the first node is 0 (since we cannot select the first node) and the maximum sum at the second node is the value of the first node (since we can select both the first node and its child).

Then we loop from the third node to the last node, update the maximum sum at each node by choosing the maximum sum of either the previous node (`dp[i - 1]`) or the sum of the previous two nodes (`dp[i - 2] + tree[i - 1]`).

Finally, the function returns the maximum sum at the last node which is the solution to the problem.