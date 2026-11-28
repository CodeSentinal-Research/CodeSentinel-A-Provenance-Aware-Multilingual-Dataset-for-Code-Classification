class ListNode {
  constructor(val = 0, prev = null, next = null) {
    this.val = val;
    this.prev = prev;
    this.next = next;
  }
}

function flatten(root) {
  if (!root) {
    return null;
  }

  let prev = new ListNode(0);
  let head = prev;

  const inOrderTraversal = (node) => {
    if (node) {
      inOrderTraversal(node.next);
      node.next = node.child;
      node.child = null;
      prev.next = node;
      prev = node;
      inOrderTraversal(node.child);
    }
  };

  inOrderTraversal(root);
  head.next.prev = null;
  return head.next;
}

This code first checks if the root of the doubly linked list is not null. If it is, it returns null. Then it creates a new ListNode with a value of 0 as the value of the new head of the doubly linked list and null as the previous and next pointers.

The function `inOrderTraversal` is a helper function that traverses the doubly linked list in an in-order way. It takes a node as input and recursively calls itself on the next and child pointers of the node, before setting the child pointer of the node to null. It also updates the previous node to point to the node.

Finally, it calls the `inOrderTraversal` function with the root of the doubly linked list as the argument, sets the next pointer of the head node to the result of the in-order traversal, sets the previous pointer of the last node in the in-order traversal to null, and returns the head of the flattened doubly linked list.