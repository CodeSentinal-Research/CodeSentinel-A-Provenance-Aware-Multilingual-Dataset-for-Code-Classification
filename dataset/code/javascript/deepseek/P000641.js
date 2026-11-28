Sure, here is the JavaScript code to insert a new node at the end of a singly linked list:

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

function insertNodeAtEnd(head, value) {
  if (head === null) {
    head = new ListNode(value);
    return head;
  }

  let current = head;
  while (current.next !== null) {
    current = current.next;
  }

  current.next = new ListNode(value);
  return head;
}

In the above code, `ListNode` class is used to create a node of the linked list. It has a constructor that takes `val` (value of the node) and `next` (next node in the list) as arguments.

`insertNodeAtEnd` function takes `head` (head of the linked list) and `value` as arguments. If the head is null (i.e., the linked list is empty), it creates a new node with `value` as its value and assigns it as the head.

Otherwise, it iterates through the linked list until it reaches the end (i.e., the node with `next` as null). At this point, it creates a new node with `value` and assigns it as the `next` node of the last node in the list. Then it returns the head of the modified linked list.

This function assumes that the input linked list is a singly linked list and it doesn't have any circular references, i.e., no loop in the list.