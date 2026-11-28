Here is a JavaScript solution for the problem using recursion:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class ListNode {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

function binaryTreeToDoublyLinkedList(root) {
  if (root === null) return null;

  let head = binaryTreeToDoublyLinkedList(root.left);

  let node = new ListNode(root.data);
  node.next = head;

  if (head !== null) head.prev = node;

  let tail = binaryTreeToDoublyLinkedList(root.right);

  node.next = tail;

  if (tail !== null) tail.prev = node;

  return node;
}

function printList(head) {
  let curr = head;
  while (curr !== null) {
    console.log(curr.data);
    curr = curr.next;
  }
}

// Test the function
let root = new Node(10);
root.left = new Node(5);
root.right = new Node(30);
root.left.left = new Node(20);
root.left.right = new Node(40);
root.right.left = new Node(35);
root.right.right = new Node(45);

let head = binaryTreeToDoublyLinkedList(root);
printList(head);

This code defines a `Node` class for the binary tree nodes and a `ListNode` class for the doubly linked list nodes. The `binaryTreeToDoublyLinkedList` function converts the binary tree into a doubly linked list. The `printList` function is used to print the doubly linked list.

Note: The input for the binary tree is not handled in this solution. You would need to create the binary tree manually or parse the input from a file. The test case creates a binary tree as an example, and then converts it into a doubly linked list. The `printList` function is used to print the doubly linked list.