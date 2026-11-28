Here is the JavaScript solution for the problem:

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

function rearrange(head) {
  if (!head) {
    return null;
  }

  let odd = new ListNode();
  let oddHead = odd;
  let even = new ListNode();
  let evenHead = even;

  let curr = head;

  while (curr) {
    if ((curr.val & 1) === 0) {
      even.next = curr;
      even = even.next;
    } else {
      odd.next = curr;
      odd = odd.next;
    }
    curr = curr.next;
  }

  odd.next = evenHead.next;

  return oddHead.next;
}

This solution uses two separate linked lists, `odd` and `even`, for storing the odd and even nodes in the linked list respectively. We initialize `odd` and `even` with a sentinel node (a node with a null `next` pointer). The `curr` pointer is used to traverse the linked list. For each node, we check if the node's value is odd (`curr.val & 1` returns 1 if the value is odd, 0 if it is even). If the node is even, we append it to the `even` list. Otherwise, we append it to the `odd` list. After the loop, we connect the `odd` list's tail to the `even` list's head, effectively merging the two lists. The sentinel node's `next` pointer is then set to point to the head of the rearranged linked list.

This solution assumes that the linked list is already initialized and has nodes with integer values. If the input linked list is not initialized or has nodes with different types of values, the code might not behave as expected.