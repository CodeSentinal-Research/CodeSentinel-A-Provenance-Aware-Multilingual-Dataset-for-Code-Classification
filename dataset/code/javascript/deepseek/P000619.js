Here is the JavaScript solution for the given problem:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function deleteMiddleNode(head) {
    if (!head.next) {
        return null;
    }

    let slow = head;
    let fast = head;
    let prevSlow = head;

    // Move fast twice as fast as slow
    while (fast && fast.next && fast.next.next) {
        fast = fast.next.next;
        prevSlow = slow;
        slow = slow.next;
    }

    // Unlink the middle node
    prevSlow.next = slow.next;
    slow.next = null;

    return head;
}

// Test
let head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
head.next.next.next = new ListNode(4);
head.next.next.next.next = new ListNode(5);

let newHead = deleteMiddleNode(head);

while (newHead) {
    console.log(newHead.val);
    newHead = newHead.next;
}

This code first checks if the list has only one node, if so, it returns an empty list. If there are more than one nodes, it uses two pointers (slow and fast) to traverse the list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle of the list. Then it unlinks the middle node by setting the next of the previous node to the node after the middle node. Finally, it returns the new head of the list.