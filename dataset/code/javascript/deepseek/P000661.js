Here is the JavaScript code to remove consecutive duplicate nodes from a singly linked list:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function removeDuplicates(head) {
    if (head === null || head.next === null) {
        return head;
    }

    let current = head;
    while (current.next !== null) {
        if (current.val === current.next.val) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }
    return head;
}

// Testing the code
let head = new ListNode(1);
head.next = new ListNode(1);
head.next.next = new ListNode(2);
head.next.next.next = new ListNode(3);
head.next.next.next.next = new ListNode(3);

removeDuplicates(head);

// Print the linked list
let current = head;
while (current !== null) {
    console.log(current.val);
    current = current.next;
}

In this code, we create a ListNode class to represent each node in the linked list. The removeDuplicates function iterates through the linked list and checks if the current node's value is equal to the next node's value. If it is, it skips the next node. If it's not, it moves the current node to the next node.

The code then creates a linked list with four nodes, and removes the consecutive duplicate nodes. Finally, it prints the linked list.