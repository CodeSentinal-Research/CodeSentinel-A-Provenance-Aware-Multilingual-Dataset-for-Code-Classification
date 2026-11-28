Here is the JavaScript code to solve the problem.

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function removeEveryNthNode(head, N) {
    let current = head;
    let previous = head;
    let index = 1;
    while (current !== null) {
        if (index % N === 0) {
            if (previous === current) {
                // if removing the head node
                head = head.next;
                if (head !== null) {
                    previous.next = head;
                }
            } else {
                previous.next = current.next;
            }
        }
        previous = current;
        current = current.next;
        index++;
    }
    return head;
}
This code first sets up a ListNode class to create linked list nodes. It then creates a function `removeEveryNthNode(head, N)` that takes in the head of a linked list and N as inputs.

In this function, it iterates over the linked list using a pointer `current` and a pointer `previous`. `Index` is used to keep track of the current position in the linked list.

For each node in the linked list, it first checks if the current node's index is divisible by N (i.e., the node to be removed is every N-th node). If the removal should occur at the head of the list, the head is moved to the next node. If it should not occur at the head, the previous node's next pointer is set to the current node's next pointer.

Finally, the function returns the head of the modified linked list.