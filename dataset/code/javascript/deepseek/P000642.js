Here's the JavaScript code that inserts a new node at a given position in a linked list:

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function insertNodeAtPosition(head, position, insertVal) {
  let newNode = new ListNode(insertVal);
  let curNode = head;

  if (!head) {
    newNode.next = newNode; // the new node becomes the next to itself
    head = newNode;
  } else if (position == 0) {
    while ((curNode.next != head) && (curNode != head)) {
      curNode = curNode.next;
    }
    curNode.next = newNode;
    newNode.next = head;
    head = newNode;
  } else {
    let prevNode, curNode;
    curNode = head;
    prevNode = null;
    let index = 0;
    while (index < position) {
      prevNode = curNode;
      curNode = curNode.next;
      index++;
    }
    prevNode.next = newNode;
    newNode.next = curNode;
  }
  return head;
}

This code first checks if the head is null, if so, it assigns the new node to be the next to itself and sets the head to the new node. 

If the position is 0, it traverses the list to find the last node and then sets the next of the new node to the head. It then sets the head of the list to the new node.

If the position is not 0, it creates a loop and inserts a new node at the specified position. The loop continues until the specified position is reached or until the current node is the last node. In this case, the new node is set to point to the node after the current node.