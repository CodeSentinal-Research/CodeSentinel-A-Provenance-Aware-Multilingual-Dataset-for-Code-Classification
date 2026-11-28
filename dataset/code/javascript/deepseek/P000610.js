Here is the JavaScript code for your problem:

function mergeNodes(n) {
  let dummy = new ListNode(0), current = dummy;
  let sum = 0;

  while (n != null) {
    if (n.val !== 0) {
      sum += n.val;
    } else {
      if (sum !== 0) {
        current.next = new ListNode(sum);
        current = current.next;
        sum = 0;
      }
    }
    n = n.next;
  }

  if (sum !== 0) {
    current.next = new ListNode(sum);
  }

  return dummy.next;
}

This function creates a dummy node and a current node. It then iterates over the linked list. If the current node's value is not zero, it adds the current node's value to the sum. If the current node's value is zero, it creates a new node with the sum and adds it to the list. It then resets the sum and continues to the next node. If there are still non-zero values in the list, it creates a new node with the sum and adds it to the list. Finally, it returns the dummy's next node, which is the modified linked list.