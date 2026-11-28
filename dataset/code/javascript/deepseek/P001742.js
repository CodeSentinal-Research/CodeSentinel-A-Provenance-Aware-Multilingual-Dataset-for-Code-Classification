Sure, here is the JavaScript code:

function solve(root) {
    if (root === null) {
        return;
    }

    let queue = [root];
    while (queue.length) {
        let node = queue.pop();
        if (!node.left && !node.right) {
            console.log(node.value);
        }
        if (node.right) {
            queue.push(node.right);
        }
        if (node.left) {
            queue.push(node.left);
        }
    }
}

In this code, we use a queue data structure to traverse the binary tree from right to left. We start by adding the root to the queue. We then enter a loop that continues until the queue is empty. In each iteration of the loop, we remove a node from the queue and check if it's a leaf node. If it is, we print its value. If it's not, we add its children to the queue for future iterations. This way, we ensure that we print all the leaf nodes in the order they were encountered.