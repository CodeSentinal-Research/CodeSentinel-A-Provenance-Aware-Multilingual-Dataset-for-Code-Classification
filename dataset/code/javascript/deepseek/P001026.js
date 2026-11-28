Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = parseInt(rl.readline());

rl.on('line', (line) => {
    const [n, ...parents] = line.split(' ').map(Number);
    const parentIndices = [...new Set(parents)].sort((a, b) => a - b);

    if (!isValidCompleteBinaryHeap(parentIndices, n)) {
        console.log('NO');
    } else {
        console.log('YES');
    }

    testCases--;
    if (testCases === 0) rl.close();
});

function isValidCompleteBinaryHeap(parentIndices, n) {
    let stack = [];

    for (let i = 1; i <= n; i++) {
        let index = i - 1;
        let parent = parentIndices[index];

        if (parent !== -1 && (parent >= n || parent < i)) {
            return false;
        }

        if (parent !== -1) {
            while (stack.length > 0 && stack[stack.length - 1] !== parent) {
                stack.pop();
            }

            if (stack.length === 0) {
                return false;
            }
        }

        stack.push(i);
    }

    return true;
}

This program reads the number of test cases from the input, then for each test case, it reads the number of nodes and the parent indices. It then calls the `isValidCompleteBinaryHeap` function with the given parameters, and prints 'YES' if the structure is a complete binary heap, 'NO' otherwise. It does this for all test cases.

The `isValidCompleteBinaryHeap` function checks whether the parent indices of each node satisfy the complete binary heap property. It uses a stack to keep track of the nodes in the current subtree rooted at the current node. If the current node is a root of a larger subtree, it pops the current node from the stack, because the popped node must be the parent of the current node. If the stack is not empty and the popped node is not the parent of the current node, or if the current node is a leaf, the function returns false. If the stack is empty, it means the current node is a root of a larger subtree, and the function returns true.