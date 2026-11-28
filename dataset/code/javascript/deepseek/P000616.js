Here is the JavaScript code for the given problem:

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

const reverseNodesInEvenPositions = (head) => {
  if (!head || !head.next || !head.next.next) {
    return head;
  }

  let prev = head;
  let curr = head.next;
  let next = curr.next;
  let evenHead = curr;

  while (next) {
    prev.next = next;
    curr.next = next.next;
    next.next = evenHead;

    prev = curr;
    curr = curr.next;
    next = curr.next;
  }

  return evenHead;
};

In this code, a helper class `ListNode` is used to create list nodes. The function `reverseNodesInEvenPositions` takes the head of the list as input. If the list is empty or has only one node, it returns the list.

The function first checks if there is at least a third node in the list. If not, it returns the list as is because there are fewer than three nodes in the list.

The `prev`, `curr`, and `next` variables hold the previous, current, and next nodes in the list. `evenHead` is the head of the list at the even position.

The while loop iterates through the list, reversing each node at an even position by changing the next of each node to the previous node, and the previous of each node to the current node.

Finally, it returns the `evenHead` node, which is the head of the list at the even position.