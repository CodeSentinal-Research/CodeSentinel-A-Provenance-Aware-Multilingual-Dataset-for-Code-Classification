Here is the JavaScript code for reversing a singly linked list:

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

function reverseList(head) {
  let prevNode = null;
  let currentNode = head;

  while (currentNode !== null) {
    let nextNode = currentNode.next;
    currentNode.next = prevNode;
    prevNode = currentNode;
    currentNode = nextNode;
  }

  head = prevNode;
  return head;
}

In this code, a class `ListNode` is defined. The `ListNode` constructor takes two parameters: `val` which represents the value of the node, and `next` which represents the next node in the linked list.

The `reverseList` function takes the head of the linked list as input. It initializes three variables: `prevNode`, `currentNode`, and `nextNode`. `prevNode` is initially set to null because the last node will point to null, and `currentNode` is set to the head of the linked list.

Then, a while loop is started which continues until `currentNode` is not null. Inside the loop, the `nextNode` is set to the next node, then the next node points to the previous node (i.e., `currentNode.next` is set to `prevNode`), and finally, `prevNode` and `currentNode` are moved one step forward.

Finally, after the loop ends, the head of the linked list is set to `prevNode`. This means the last node (`currentNode`) points to the previous node (`prevNode`), and the first node (`head`) points to `prevNode`.

This is how we reverse a singly linked list. The time complexity is O(n), where n is the number of nodes in the linked list. The space complexity is O(1) as we only use a constant amount of space.