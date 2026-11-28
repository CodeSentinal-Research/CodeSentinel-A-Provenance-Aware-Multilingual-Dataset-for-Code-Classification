function inorder(root, inorder) {
    if (root) {
        inorder(root.left, inorder);
        inorder(root.right, inorder);
        inorder.push(root.val);
    }
}

function buildTree(inorder, priority) {
    if (!inorder.length) {
        return null;
    }
    let maxIndex = inorder.indexOf(maxValue(inorder));
    let root = {
        val: inorder[maxIndex],
        left: buildTree(inorder.slice(0, maxIndex), priority),
        right: buildTree(inorder.slice(maxIndex + 1), priority)
    };
    return root;
}

function maxValue(inorder) {
    return inorder.reduce((max, val) => val > max ? val : max, inorder[0]);
}

let inorderString = readline();
let inorder = inorderString.split(' ').map(Number);
let priorityString = readline();
let priority = priorityString.split(' ').map(Number);

let root = buildTree(inorder.slice(), priority);

function printTree(root) {
    if (root) {
        console.log(root.val);
        printTree(root.left);
        printTree(root.right);
    }
}

printTree(root);

In this code, we first define the inorder traversal of a binary search tree and the priority of each key. Then, we construct the Cartesian Tree using the inorder traversal and priority. The `buildTree` function uses the `inorder` array to construct the Cartesian Tree. If the `inorder` array is empty, it returns null. Otherwise, it finds the maximum value in the `inorder` array, removes it from the array, and constructs a left child and right child for the root. The `maxValue` function returns the maximum value in the array.

The `printTree` function is a recursive function that prints the values of the Cartesian Tree in inorder traversal.

Please note that this is a simple solution and it assumes that the input is correctly formatted. It doesn't handle any errors or edge cases.