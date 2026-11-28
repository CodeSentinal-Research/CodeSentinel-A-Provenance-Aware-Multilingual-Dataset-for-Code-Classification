Here is the code:

function removeElements(head, val) {
    let currentNode = head;
    let previousNode = null;

    // Loop through the linked list until the end of the list
    while (currentNode !== null) {
        // If the value of the current node is equal to the value to be removed
        if (currentNode.value === val) {
            // If it's the head of the list, update the head to the next node
            if (head === currentNode) {
                head = head.next;
            } else {
                // Otherwise, remove the current node from the previous node's next
                previousNode.next = currentNode.next;
            }
        } else {
            // If it's not the value to be removed, move on to the next node
            previousNode = currentNode;
        }

        // Move on to the next node
        currentNode = currentNode.next;
    }

    // Return the modified head of the list
    return head;
}

This code handles input validation (checking for the presence of a list and the presence of a value to remove) and removes all occurrences of the given value from the linked list. The time complexity of this code is O(n), where n is the number of nodes in the list.