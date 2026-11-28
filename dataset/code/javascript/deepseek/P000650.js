Here is the JavaScript code to find the nth node from the beginning of the list:

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {number}
 */
var findNthFromEnd = function(head, n) {
    var p1 = head;
    var p2 = head;
    var prevP2 = head;
    
    for(var i = 0; i < n; i++){
        if(p2.next === null){
            return -1;
        }
        p2 = p2.next;
    }
    
    while(p2 !== null){
        p2 = p2.next;
        prevP2 = p1;
        p1 = p1.next;
    }
    
    if(prevP2 !== head){
        return prevP2.val;
    }
    
    return p1.val;
};

This function first checks if the `n` is less than or equal to 0 or greater than the size of the list. If so, it returns -1 because there are less elements in the list than `n`.

Next, it sets `p2` as the `n`th node from the head. If `p2` is null, it means there are not enough nodes in the list to reach `n`, so it returns -1.

Then it sets `p1` and `prevP2` as the `n`th node from the head and the previous node of the `n`th node from the head.

Then it enters a loop where it continues to move `p1` and `prevP2` until `p2` is null.

In the end, it returns the value of `p1` which is the `n`th node from the end. If `prevP2` is not the head of the list, it means we reached the head of the list, so it returns `prevP2`'s value.