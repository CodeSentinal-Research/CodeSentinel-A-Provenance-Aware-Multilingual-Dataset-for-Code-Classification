Here is a solution using JavaScript. 

The code uses a binary tree as a node and serializes the tree into a string, then reconstructs the tree from the string.

class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

function serialize(root) {
    if (root === null) return "";
    let str = root.val + ",";
    str += serialize(root.left);
    str += serialize(root.right);
    return str;
}

function deserialize(data) {
    if (data === "") return null;
    let arr = data.split(",");
    let root = new TreeNode(arr[0]);
    let stack = [root];
    let i = 1;
    while (i < arr.length) {
        let node = stack.pop();
        if (arr[i] !== "null") {
            node.right = new TreeNode(arr[i]);
            stack.push(node.right);
        }
        i++;
        if (arr[i] !== "null") {
            node.left = new TreeNode(arr[i]);
            stack.push(node.left);
        }
        i++;
    }
    return root;
}

In this solution, we use a stack to track the nodes in the binary tree. We start by creating a new TreeNode for the root of the tree and pushing it into the stack. Then we iterate over the data, popping nodes from the stack and adding their children to the stack. If there are still elements in the data, we add them to the stack as children of the current node.

This solution assumes that the input data is a string representation of a binary tree, where each node is separated by a comma, and the left and right children of each node are separated by a comma. The string representation of the root node is followed by the serialization of the left and right subtrees, and so on.

Please note that this solution does not account for checking if the data is valid (i.e., it is a correct serialization of a binary tree). This would require additional error checking and handling, which is not included in this solution.