class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

function removeLeaves(root, x) {
    if (!root) {
        return null;
    }

    root.left = removeLeaves(root.left, x);
    root.right = removeLeaves(root.right, x);

    if (!root.left && !root.right && root.val === x) {
        return null;
    } else {
        return root;
    }
}

function buildTree(lines) {
    let root = new TreeNode(lines.shift());
    let current = root;

    while (lines.length > 0) {
        let line = lines.shift();
        if (line !== null) {
            current.left = new TreeNode(line);
            current = current.left;
        } else {
            current.right = null;
            current = current.right;
        }
    }

    return root;
}

let input = [
    [3, 5, 1, 6, 2, 7, null, null, null, null, 4],
    2,
    [3, 5, 1, 6, 2, 7, null, null, null, null, 4],
    5
];

let root = buildTree(input[0]);
console.log(root);
root = removeLeaves(root, input[2]);
console.log(root);

Please note that this is a JavaScript solution and it is not a complete solution to your problem. You may need to adjust the code to fit your specific use case.