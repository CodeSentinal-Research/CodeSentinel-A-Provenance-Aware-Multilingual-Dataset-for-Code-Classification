Here is the JavaScript code for the problem:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function pairWiseSwap(head) {
    if (!head || !head.next) return head;

    const nextNode = head.next;
    head.next = pairWiseSwap(nextNode.next);
    nextNode.next = head;

    return nextNode;
}

The code above defines a `ListNode` class with a constructor for initializing a node with a value (defaulting to 0) and a next pointer (defaulting to null). 

The `pairWiseSwap` function is the main function which accepts the head of a linked list as input. If the linked list is empty or only has one node, then the function simply returns the head of the list. 

The function uses recursion to swap the first two nodes in the list, then it recursively calls the `pairWiseSwap` function on the rest of the list. 

This will effectively swap each pair of nodes in the list, but the list will not have the nodes swapped back. To swap the nodes again, you would need to call `pairWiseSwap(head)` again.

This code assumes that the input linked list is a singly linked list. If the input linked list is more complex (e.g., circular linked list), you will need to modify the code to handle that case appropriately.