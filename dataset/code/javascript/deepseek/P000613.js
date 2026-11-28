Here is a JavaScript solution using a HashMap to keep track of the nodes that have already been encountered:

class ListNode {
  constructor(x) {
    this.val = x;
    this.next = null;
  }
}

function removeDuplicates(head) {
  if (head === null || head.next === null) {
    return head;
  }

  var current = head;
  var map = {};

  while (current !== null) {
    if (!map[current.val]) {
      map[current.val] = true;
      current = current.next;
    } else {
      var nextNode = current.next;
      if (nextNode !== null) {
        current.next = nextNode.next;
      } else {
        current.next = null;
     .
.
.
.
      }
    }
  }

  return head;
}

Please note that I used a `ListNode` class here to create a new node in the linked list. The `ListNode` constructor takes a value `x` and sets the value of the node, and `null` for the `next` pointer.

This function goes through each node in the list, and checks if the value of the current node is in the map. If the value is not in the map (i.e., it is a new value), the map is updated and the current node is moved to the next node. If the value is already in the map (i.e., it is a duplicate), the current node's next pointer is set to the next node's next pointer (skipping over the duplicate node), effectively removing the duplicate node from the linked list.