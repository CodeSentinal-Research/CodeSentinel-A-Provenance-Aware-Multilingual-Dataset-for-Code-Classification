Here is the JavaScript code for the problem:

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {ListNode} head
 * @return {number}
 */
var sumNodes = function(head) {
    let sum = 0;
    while(head !== null) {
        sum += head.val;
        head = head.next;
    }
    return sum;
};

In this code, I created a function `sumNodes` which takes in the head of a linked list as input. It initializes a variable `sum` to 0. In a while loop, it adds the value of the current node to `sum` and then moves to the next node by updating `head` to `head.next`.

When `head` is `null` (which is the last node in the list), the loop stops, and the function returns `sum`, which is the sum of all node values in the list.