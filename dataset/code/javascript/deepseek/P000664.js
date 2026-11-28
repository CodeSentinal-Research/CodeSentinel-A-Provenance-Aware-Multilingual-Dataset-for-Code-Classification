Here is the JavaScript code:

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteAlternateNodes = function(head) {
    if (!head) return null;
    let node = head;
    while (node && node.next) {
        node.next = node.next.next;
        node = node.next;
    }
    return head;
};

This JavaScript function, `deleteAlternateNodes`, takes a linked list head as input and deletes every alternate node starting from the second node in the linked list. It does this by changing the 'next' pointer of each node to its next node's next node, effectively skipping over every other node. The returned head of the linked list is the input head, but now with every alternate node deleted.

The `node.next = node.next.next;` line in the while loop is what makes this work. It's essentially saying "skip this node and go to the next node after it", effectively deleting the node after it.

The while loop continues until the end of the list (which happens when `node` is `null`), and then returns the new head of the list. 

The input linked list is modified in-place, meaning that no additional memory is used. 

Please note that this is a Node.js solution for the problem. If you are using a JavaScript environment, you might want to adjust the code a bit depending on the specifics of your environment.