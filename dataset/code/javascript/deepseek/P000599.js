Here's the JavaScript code to solve the problem:

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if (head === null || head.next === null) return head;
    
    var cur = head;
    while(cur !== null && cur.next !== null) {
        if (cur.val === cur.next.val) {
            cur.next = cur.next.next;
        } else {
            cur = cur.next;
        }
    }
    return head;
};

The function deleteDuplicates takes the head of the list as input and returns the new head of the list. It initializes a pointer 'cur' to point at the head of the list. In a while loop, it checks if the current and next node's values are the same. If they are, it skips the next node (i.e., 'cur.next.next'), otherwise, it moves the 'cur' pointer to the next node in the list. The loop continues until the end of the list is reached.