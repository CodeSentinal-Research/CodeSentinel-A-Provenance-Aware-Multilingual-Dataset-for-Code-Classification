Here is the JavaScript code for the given problem:

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input = '';
process.stdin.on('data', function(data) {
    input += data;
});

process.stdin.on('end', function() {
    var N = parseInt(input.split('\n')[0]);
    var arr = input.split('\n').slice(1).map(Number);
    var tree = new TreeNode(arr[0]);
    var currentNode = tree;
    for (var i = 1; i < arr.length; i += 2) {
        var node = new TreeNode(arr[i + 1]);
        currentNode.left = arr[i] === 0 ? null : node;
        if (arr[i] !== 0) {
            currentNode.right = node;
            currentNode = node;
        } else {
            currentNode = currentNode.left;
        }
    }
    reverseAlternate(tree);
});

function TreeNode(val, left, right) {
    this.val = val || 0;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

function reverseAlternate(root) {
    if (root == null) {
        return;
    }
    if ((root.left != null && root.left.left == null) || (root.right != null && root.right.left == null)) {
        if (root.left) {
            var temp = root.left;
            root.left = temp.right;
            temp.right = root.right;
            root.right = temp.left;
            temp.left = root.left;
            root.left = temp;
        }
        if (root.right) {
            var temp = root.right;
            root.right = temp.left;
            temp.left = temp.right;
            temp.right = root.left;
            root.left = temp.left;
            temp.left = root.right;
            root.right = temp.right;
        }
    } else {
        reverseAlternate(root.left);
        reverseAlternate(root.right);
    }
}

This code reads the input and creates a binary tree from the input. It then calls the `reverseAlternate` function to reverse the values at every alternate level. The `reverseAlternate` function uses a recursive approach to traverse the tree and swap the left and right children of each node at each level, based on the level of the node (odd level: left, even level: right).