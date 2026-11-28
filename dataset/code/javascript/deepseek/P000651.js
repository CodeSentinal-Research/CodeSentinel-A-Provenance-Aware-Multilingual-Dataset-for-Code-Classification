Here is a simple JavaScript solution for the problem.

In this solution, we use a class `ListNode` to represent the nodes of the linked list and a class `LinkedList` to represent the whole list.

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

class LinkedList {
    constructor(head = null) {
        this.head = head;
    }

    deleteLastNode() {
        if (!this.head) return this.head;

        let prev = this.head;
        let slow = this.head;
        let fast = this.head;

        while (fast && fast.next) {
            fast = fast.next.next;
            prev = slow;
            slow = slow.next;
        }

        // if there is only one node left, then set head as null
        if (!fast) {
            this.head = null;
        }
        // if there are two nodes left, then skip the last node
        else {
            prev.next = null;
        }

        return this.head;
    }
}

This solution works by using the fast-slow pointer strategy to detect the end of the list. The slow pointer moves one node at a time, and the fast pointer moves two nodes at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the end of the list. We can then delete the last node by adjusting the previous node's `next` pointer.