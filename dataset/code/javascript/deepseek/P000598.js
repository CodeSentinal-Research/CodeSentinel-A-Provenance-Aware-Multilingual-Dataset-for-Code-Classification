function ListNode(val = 0, next = null) {
  this.val = val;
  this.next = next;
}

function reverseLinkedList(head, left, right) {
  if (left === right) {
    return head;
  }

  let current = head;
  let prevGroup = null;

  while (left > 1) {
    prevGroup = current;
    current = current.next;
    left--;
  }

  let nextGroup = current;
  let tail = current;

  while (right > 1) {
    tail = current;
    current = current.next;
    right--;
 
    if (!current) {
      break;
    }
  }

  let prev = null;
  let tempPrev = prevGroup;
  let tempNext = nextGroup;

  while (prevGroup && prevGroup.next !== nextGroup) {
    let next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  if (tempPrev) {
    tempPrev.next = prev;
  } else {
    head = prev;
  }

  tempPrev = prev;
  prev = null;
  current = nextGroup;

  while (tempPrev && tempPrev.next !== tempNext) {
    let next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  if (tempPrev) {
    tempPrev.next = prev;
  } else {
    head = prev;
  }

  return head;
}
This code first finds the precursor and successor nodes of the sublist to be reversed in the list. Then, it reverses the linked list by setting the next of the current node to the previous node and updates the previous node and current node for the next iteration.