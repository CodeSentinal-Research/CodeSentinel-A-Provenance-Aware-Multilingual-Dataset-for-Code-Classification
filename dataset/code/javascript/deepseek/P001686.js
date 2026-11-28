Here is the JavaScript code to solve the problem:

function findPredecessor(root, target) {
    // Initialize queue and predecessor
    let queue = [[root, null]];
    let predecessor = null;

    // Level order traversal
    while (queue.length > 0) {
        let [node, prev] = queue.shift();

        // If current node is the target
        if (node.value === target) {
            predecessor = prev;
        }

        // Add children to queue
        if (node.left) {
            queue.push([node.left, node]);
        }
        if (node.right) {
            queue.push([node.right, node]);
        }
    }

    // Print the result
    if (predecessor === null) {
        console.log('NONE');
    } else {
        console.log(predecessor.value);
    }
}

This code uses a breadth-first search (BFS) approach to traverse the binary tree in a level order manner. It initially sets the root of the tree as the current node and its predecessor as null. Then, it starts a loop that continues until the queue is empty. In each iteration, it removes the first node from the queue, checks if it is the target, and if so, sets its predecessor. Then, it adds its children to the queue. After the loop ends, it checks if a predecessor was found, and if not, prints 'NONE', otherwise, it prints the predecessor's value.