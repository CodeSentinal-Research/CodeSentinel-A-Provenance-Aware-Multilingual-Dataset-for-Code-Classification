Here is the JavaScript code to solve the problem. This code uses a recursive approach to traverse the binary tree and check for each path whether its sum equals to K.

function solve(nodeValues, tree, k, path = [], index = 0) {
    if (index === tree.length) {
        if (path.reduce((a, b) => a + b, 0) === k) {
            console.log(path);
        }
        return;
    }

    path.push(nodeValues[index]);
    solve(nodeValues, tree[index], k, path, index + 1);
    path.pop();

    if (index + 1 < tree.length) {
        solve(nodeValues, tree[index], k, path, index + 1);
    }
}

function main() {
    const [N, ...nodeValues] = readline().split(' ').map(Number);
    const tree = readline().split(' ').map(Number);
    const k = Number(readline());

    solve(nodeValues, tree, k);
}

function readline() {
    return process.stdin.readline().trim();
}

main();

In the above code, the `solve` function is called recursively for each node in the tree. The `path` array is used to track the path, and the `index` variable is used to traverse the tree. The path is printed when the sum of its node values is equal to K. The base case is when the index is equal to the length of the tree, indicating that we've traversed all nodes. The recursive case is when we've reached a leaf node (i.e., the index is less than the length of the tree), in which case we print the path and return. If we haven't reached a leaf node (i.e., the index is not less than the length of the tree), we recurse for the next node.