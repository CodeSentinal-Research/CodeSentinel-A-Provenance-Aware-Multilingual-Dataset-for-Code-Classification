function MorrisInorderTraversal(root) {
    var stack = [];
    var current = root;

    while(current || stack.length) {
        if(current) {
            // Reach the left most Node of the current Node
            stack.push(current);
            current = current.left;
        } else {
            // Backtrack from the empty subtree and visit the node
            // at the top of the stack; however, if the right child is the
            // current node, then print the node and move on to the right child
            current = stack.pop();
            console.log(current.data);
            current = current.right;
        }
    }
}