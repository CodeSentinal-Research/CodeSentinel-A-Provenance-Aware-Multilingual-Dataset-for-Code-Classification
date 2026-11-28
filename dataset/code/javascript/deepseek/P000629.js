Here is the JavaScript code for the problem:

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var deleteEveryKthNode = function(head, k) {
    var dummy = new ListNode(0);
    dummy.next = head;
    var prev = dummy;
    var curr = head;

    while (curr) {
        for (var i = 1; i < k && curr; i++) {
            curr = curr.next;
        }
        if (curr) {
            prev.next = curr.next;
            curr = curr.next;
        }
        prev = prev.next;
    }
    return dummy.next;
};
In this code, a dummy node is used to simplify the list handling. In the while loop, we keep moving k nodes forward until we reach the end of the list. After that, we skip k nodes (or until end of list if k is larger than length of list). If curr still points to a node, we skip it. Otherwise, we skip all k-1 nodes.