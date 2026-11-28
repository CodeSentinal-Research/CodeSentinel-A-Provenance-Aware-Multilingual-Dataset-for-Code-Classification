Here is the JavaScript code for the problem:

class ListNode {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

function deleteNodes(head) {
  if (!head || !head.next) {
    return head;
  }

  ListNode* prev = null;
  ListNode* curr = head;

  while (curr !== null) {
    if (curr.next !== null && curr.next.val > curr.val) {
      if (prev === null) {
        head = curr.next;
      } else {
        prev.next = curr.next;
      }
      ListNode* del = curr.next;
      curr.next = curr.next.next;
      delete del;
    } else {
      prev = curr;
    }
    curr = curr.next;
  }

  return head;
}

This JavaScript code defines a helper class `ListNode` for a singly linked list. The `deleteNodes` function is then defined to solve the problem. It first checks if the head or the head's next node exists, and if not, it returns the head.

Then, two pointers, `prev` and `curr`, are initialized to the head. `prev` is used to track the previous node in case we need to skip the current node, and `curr` is used to iterate over the linked list.

The while loop continues until `curr` is null, which means we've reached the end of the list. Inside the loop, if the current node's next node exists and its value is greater than the current node's value, the current node's next node is deleted and the current node's next node is set to the next node's next node. If the current node does not have a next node or its value is not greater than the current node's value, the current node is set to the next node.

Finally, the function returns the head of the modified linked list.