function insertLevels(root, x, d) {
    // Base case
    if (d === 0) {
        root.val = x;
        return;
    }

    // Insert left and right nodes
    if (root.left) {
        insertLevels(root.left, x, d - 1);
    } else {
        root.left = { val: x, left: null, right: null };
    }

    if (root.right) {
        insertLevels(root.right, x, d - 1);
    } else {
        root.right = { val: x, left: null, right: null };
    }
}

// Construct the tree
function constructTree(input) {
    const root = { val: input[0], left: null, right: null };
    for (let i = 1; i < input.length; i++) {
        insertLevels(root, input[i], i);
    }
    return root;
}

// Handle input
process.stdin.setEncoding('utf8');
process.stdin.on('data', (input) => {
    const lines = input.split('\n');
    const N = parseInt(lines[0]);
    const arr = lines.slice(1, N).map(Number);
    const X = parseInt(lines[N]);
    const D = parseInt(lines[N + 1]);

    const root = constructTree(arr);
    insertLevels(root, X, D);

    console.log(root);
});
This code constructs the tree from an array, then recursively inserts the new nodes until the desired depth. The `insertLevels` function is a helper function that inserts a new level at the desired depth. The `constructTree` function is used to construct the tree from the given array. The input is taken from standard input.