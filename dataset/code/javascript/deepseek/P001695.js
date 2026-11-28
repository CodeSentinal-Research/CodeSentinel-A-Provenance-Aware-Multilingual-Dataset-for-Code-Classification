Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = Number(rl.line());

rl.on('line', (line) => {
    let [N, ...inputs] = line.split(' ').map(Number);
    let tree = new Array(N).fill(null).map((_, i) => inputs[i]);
    let sum = dfs(tree, 0);
    console.log(sum);
    testCases--;
    if(testCases === 0) rl.close();
});

function dfs(tree, nodeIndex) {
    if(tree[nodeIndex] === null) return 0;

    let sum = 0;

    sum += tree[nodeIndex];

    sum += dfs(tree, 2 * nodeIndex + 1);
    sum += dfs(tree, 2 * nodeIndex + 2);

    return sum;
}

This code reads the number of test cases from the standard input, then for each test case, it reads the tree data and calculates the sum of root-to-leaf binary numbers.