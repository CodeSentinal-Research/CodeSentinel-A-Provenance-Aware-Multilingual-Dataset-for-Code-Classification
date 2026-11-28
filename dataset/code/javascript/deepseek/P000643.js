Here is a simple implementation of the problem in JavaScript:

function removeNodesWithValue(head, value) {
    if (!head) return head;

    while (head && head.value === value) {
        head = head.next;
    }

    let current = head;

    while (current && current.next) {
        if (current.next.value === value) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }

    return head;
}

In this code, the function `removeNodesWithValue` takes in the head of the linked list and the value to be removed as parameters. If the head of the linked list is null, it returns the head. The while loop is used to delete all nodes whose value is equal to the provided value. The while loop goes through all the nodes in the list, and if the current node's value is equal to the provided value, it sets the current node's next to be the next node's next node. If the current node's value is not equal to the provided value, it moves to the next node.