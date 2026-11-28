Here is the code for the solution:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

class LinkedList {
    constructor(head = null) {
        this.head = new ListNode(head);
    }
    
    removeNodes(n) {
        var current = this.head;
        var nextNode;
        var prev = null;
        while(current) {
            nextNode = current.next;
            if(nextNode && nextNode.val >= n) {
                if(prev) {
                    prev.next = nextNode;
                } else {
                    this.head = nextNode;
                }
            } else {
                prev = current;
            }
            current = nextNode;
        }
        return this.head;
    }
}


This is a JavaScript implementation of the problem. The `LinkedList` class is used to create a linked list, and the `removeNodes` method is used to remove nodes with a value greater than or equal to `n`. 

The `ListNode` class is used to create individual nodes in the linked list. 

The `while` loop in the `removeNodes` method iterates through the linked list, and for each node, it checks if the next node exists and if its value is greater than or equal to `n`. If it does, the previous node's `next` is set to the current node's `next`, effectively skipping the current node. If it doesn't, the current node becomes the new `head` of the linked list.

The `prev` variable is used to keep track of the previous node while iterating through the linked list.

Please note that this code assumes that the input values are always valid, i.e., they are within the range 1 ≤ n ≤ 10^5 and 1 ≤ node.value ≤ 10^5. If these assumptions are not valid, additional checks would need to be added to handle these cases.