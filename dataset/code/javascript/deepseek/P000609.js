Here is the JavaScript code to solve the problem:

class ListNode {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

function removeZeroSumSublists(head) {
  let dummy = new ListNode(0);
  dummy.next = head;
  let sum = 0;
  let map = new Map();

  while (head !== null) {
    sum += head.val;
    if (sum === 0) {
      dummy = head;
    } else if (map.has(sum)) {
      let prev = map.get(sum);
      prev.next = head.next;
    } else {
      map.set(sum, head);
    }
    head = head.next;
  }

  head = dummy.next;
  return head;
}

This code defines a linked list node `ListNode`, and a function `removeZeroSumSublists` that takes the head of the linked list as input. The function creates a dummy node with a value of 0, and sets the head of the linked list to the dummy node. It also creates a map to store the sum of consecutive nodes and their corresponding nodes.

In the while loop, the function calculates the sum of the current node and the previous node. If the sum is 0, it means we have reached the start of the sublist, so it updates the dummy node. If the sum has been seen before, it means we have found a sublist with a sum of 0, so it removes the sublist and moves the previous node's next node to the current node's next node. If the sum has not been seen before, it stores the current node and its sum in the map.

Finally, it updates the head of the linked list to the next node of the dummy node, and returns the head of the linked list.