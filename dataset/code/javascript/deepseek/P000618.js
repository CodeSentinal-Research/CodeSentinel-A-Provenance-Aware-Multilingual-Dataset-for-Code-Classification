class Node {
  constructor(x) {
    this.val = x;
    this.prev = null;
    this.next = null;
    this.random = null;
  }
}

function cloneDoublyLinkedList(head) {
  const nodes = new Map();
  let current = head;

  while(current) {
    if(!nodes.has(current)) {
      nodes.set(current, new Node(current.val));
    }

    current = current.next;
  }

  // establish the next and random pointers
  current = head;
  while(current) {
    if(current.next) {
      if(!nodes.has(current.next)) {
        nodes.set(current.next, new Node(current.next.val));
      }
      nodes.get(current).next = nodes.get(current.next);
    }

    if(current.random) {
      if(!nodes.has(current.random)) {
        nodes.set(current.random, new Node(current.random.val));
      }
      nodes.get(current).random = nodes.get(current.random);
    }

    current = current.next;
  }

  return nodes.get(head);
}

This solution works by creating a map from each node to its copy, and then setting the `next` and `random` pointers of each copy to point to the correct copy of the node in the original list. This ensures that the new list has the same structure as the original list.

Please note that the provided solution assumes that the linked list nodes can be accessed by their indices in the array, and that the array is sorted in ascending order of indices.