Here's a JavaScript code solution for the problem:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function addTwoNumbers(l1, l2) {
    let dummyHead = new ListNode(0);
    let current = dummyHead;
    let carry = 0;

    while(l1 || l2 || carry){
        let x = l1 ? l1.val : 0;
        let y = l2 ? l2.val : 0;
        let sum = carry + x + y;
        carry = Math.floor(sum / 10);
        current.next = new ListNode(sum % 10);
        current = current.next;

        if(l1) l1 = l1.next;
        if(l2) l2 = l2.next;
    }

    return dummyHead.next;
}

This code first creates a new `ListNode` object called `dummyHead` and sets its `next` property to `null`. Then, it initializes three variables: `current`, `carry` and `sum`. The `current` pointer points to the current node in the final list, while `carry` keeps track of carryover from the previous addition.

In the while loop, we first get the values of the two linked lists `l1` and `l2`. Then, we calculate the sum of the current node and carry over. We also get the carry over from the sum. After that, we create a new node with the sum mod 10 (the last digit of the sum) and append it to the `current` pointer's `next` link. Then we update `l1` and `l2` to the next nodes in the lists.

Finally, we return `dummyHead.next` which points to the first node in the final list, because `dummyHead` is the first node in the result list, so we don't need to move our `dummyHead` pointer.