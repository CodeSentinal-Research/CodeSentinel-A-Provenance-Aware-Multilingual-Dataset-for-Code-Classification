Here's the JavaScript code that splits a circular linked list into two halves:

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    append(data) {
        let newNode = new Node(data);

        if (!this.head) {
            this.head = newNode;
            this.head.next = this.head;
        } else {
            let current = this.head;
            while (current.next !== this.head) {
                current = current.next;
            }
            current.next = newNode;
            newNode.next = this.head;
        }
    }
}

function splitList(head) {
    if (!head) {
        return null;
    }

    let fast = head;
    let slow = head;

    // Detect the midpoint of the list.
    while (fast.next !== head && fast.next.next !== head) {
        fast = fast.next.next;
        slow = slow.next;
    }

    // Split the list into two halves.
    let head2 = slow.next;
    slow.next = head;

    return [head, head2];
}

// Example usage:
let list = new LinkedList();
list.append(1);
list.append(2);
list.append(3);
list.append(4);
list.append(5);

let head1 = splitList(list.head);
let head2 = splitList(list.head);

This code first creates a `Node` class to represent each node in the linked list and a `LinkedList` class to represent the whole linked list. The `LinkedList` class has a method `append` to add nodes to the list.

The `splitList` function takes the head of the list as input and returns the heads of the two halves as an array. It uses the fast-slow pointer technique to find the midpoint of the list, which is then used to split the list into two halves.

Please note that this code assumes that the input linked list is circular. If the input linked list is not circular, additional logic would be needed to handle the case where we might end up with two separate linked lists.