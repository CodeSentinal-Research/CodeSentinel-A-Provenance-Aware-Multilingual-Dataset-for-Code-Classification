Here is a JavaScript code snippet that handles the problem:

function Node(data) {
    this.data = data;
    this.left = this.right = null;
}

function largestBSTSubtree(root) {
    if (root === null) {
        return {
            isBST: true,
            min: Infinity,
            max: -Infinity,
            size: 0
        };
    }

    const left = largestBSTSubtree(root.left);
    const right = largestBSTSubtree(root.right);

    if (left.isBST && right.isBST && root.data > left.max && root.data < right.min) {
        const size = left.size + right.size + 1;
        return {
            isBST: true,
            min: Math.min(left.min, root.data),
            max: Math.max(right.max, root.data),
            size,
        };
    }

    return {
        isBST: false,
        min: Infinity,
        max: -Infinity,
        size: Math.max(left.size, right.size),
    };
}

function solve() {
    let root = null;
    let N = +process.argv[2];
    process.stdin.resume();
    process.stdin.on('data', (chunk) => {
        let str = chunk.toString();
        if (N-- > 0) {
            let [data, , nextData] = str.split(/\s+/);
            root = new Node(data);
            if (nextData) {
                root.left = new Node(nextData);
                process.stdin.pause();
            }
        } else {
            root = new Node(str);
            process.stdin.pause();
        }
    });

    let result = largestBSTSubtree(root);
    console.log(result.size);
}

solve();

This code uses depth-first search to find the largest binary search tree in the given binary tree. The `largestBSTSubtree` function is a recursive function that returns an object with the properties `isBST`, `min`, `max`, and `size`. The `isBST` property indicates whether the subtree rooted at the current node is a binary search tree, the `min` and `max` properties represent the smallest and largest values in the subtree, and the `size` property represents the size of the largest BST.

The `solve` function reads the input from the standard input, constructs the binary tree, and then calls the `largestBSTSubtree` function to get the size of the largest BST. The `console.log` statement prints the result to the standard output.

Please note that this code assumes that the input is a valid binary tree in the following format:

`N`
`data`
`data`
...

where `N` is the number of nodes in the tree, `data` is the data of each node.