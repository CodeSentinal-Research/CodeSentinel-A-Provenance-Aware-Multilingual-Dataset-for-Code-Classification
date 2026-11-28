Sure, here is the JavaScript code for your problem:

function findDepth(root) {
    if (!root) {
        return 0;
    }

    let leftDepth = findDepth(root.left);
    let rightDepth = findDepth(root.right);

    return Math.max(leftDepth, rightDepth) + 1;
}

function solve(input) {
    const N = parseInt(input[0]);
    const tree = [];
    let idx = 1;

    while (idx < input.length) {
        const node = input[idx++];
        if (node === -1) {
            tree.push(null);
        } else {
            tree.push({ value: node, left: null, right: null });
        }
    }

    let root = tree[0];

    for (let i = 0; i < N; i++) {
        console.log(findDepth(root));
    }
}

solve([5, 1, 2, 3, 4, -1, -1, -1, -1, -1, 5]);

In this code, we first define a `findDepth` function that recursively finds the depth of a node in the binary tree. The base case is when the node is null, in which case the depth is 0. If the node is not null, we find the depths of the left and right subtrees and return the maximum plus 1.

Then, we define the `solve` function. We parse the input and construct a binary tree from it. We then call `findDepth` for each node in the binary tree to find the depth of each node and print the result.

The `solve` function is called with an example input. In this example, the root node is the fifth node (index 4), and all other nodes are connected in a binary tree. The result of the function will be printed to the console.