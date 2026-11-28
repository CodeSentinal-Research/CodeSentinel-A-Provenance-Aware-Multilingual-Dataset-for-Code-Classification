Here is a JavaScript solution for the given problem.

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function insertIntoSortedLinkedList(head, insertVal) {
    if (head === null) {
        head = new ListNode(insertVal);
        return head;
    }
    
    let current = head;
    
    while(current.next !== null && current.next.val < insertVal) {
        current = current.next;
    }
    
    if (current.next === null) {
        current.next = new ListNode(insertVal);
    } else {
        let temp = current.next;
        current.next = new ListNode(insertVal);
        current.next.next = temp;
    }
    
    return head;
}
In this code, we define a ListNode class with a constructor that accepts a value and a next node. We then write a function called insertIntoSortedLinkedList that takes in the head of the linked list and a value to insert.

We first check if the head of the list is null. If it is, we create a new ListNode with the given value and return it as the head.

Next, we initialize a current node that we will traverse through the linked list.

Then, we loop until we find a node whose next node's value is less than the given value. This is because we want to insert the new node into the correct position in the list.

If we reach the end of the list (i.e., the next node is null), we create a new ListNode with the given value and set its next node to the current node's next node.

If we are not at the end of the list (i.e., the next node's value is greater than or equal to the given value), we create a new ListNode with the given value and set its next node to the current node's next node's next node.

Finally, we return the head of the linked list.