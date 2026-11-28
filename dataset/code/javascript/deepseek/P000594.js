// Node Definition
class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
  if (!head || !head.next || k <= 0) return head;
  
  // Get the tail node and the new tail
  let fast = head, slow = head;
  while (fast.next) {
    fast = fast.next;
    if (fast.next) {
      slow = slow.next;
      fast = fast.next;
    }
  }
  let tail = slow;
  
  // Break the list at tail
  let newTail = tail.next;
  tail.next = null;
  
  // Connect the tail to the head
  newTail.next = head;
  
  // Get the new head
  if (k == 1) {
    return newTail;
  } else {
    while (k > 1) {
      k--;
      newTail = newTail.next;
    }
    return newTail;
  }
};