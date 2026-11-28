Here is the JavaScript code for deleting a node in a singly linked list.

function deleteNode(node) {
    // Assign the next node to the current node's next
    node.val = node.next.val;
    // Assign the next of next node to current node's next
    node.next = node.next.next;
}
This function takes a node as input and modifies the linked list by assigning the value of the next node to the current node and then the next of the next node to the next node's next.

Please note that in a linked list, there is a reference to the next node. Hence, the 'node.next' refers to the next node in the list.

For handling the input, you can create a new node with the value and the next node, then pass it to the deleteNode function. For example:

// Create a new node with the value and the next node
var newNode = {
    val: 1,
    next: {
        val: 2,
        next: {
            val: 3,
            next: null
        }
    }
}

deleteNode(newNode);

console.log(newNode.val); // Output: 2

In this example, the value of the current node after deleting the new node is printed to the console. As expected, it prints '2', because the value of the next node after the first node is set to the value of the second node.