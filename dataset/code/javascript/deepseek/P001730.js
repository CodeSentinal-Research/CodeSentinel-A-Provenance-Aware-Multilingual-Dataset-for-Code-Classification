Here is the JavaScript code for converting a binary tree into a circular doubly linked list. 

Firstly, let's define the Node class for the binary tree:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

Then, let's define the NodeDoubly class for the doubly linked list:

class NodeDoubly {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

Then, let's define a function to convert the binary tree into a doubly linked list:

function binaryTreeToDoublyLinkedList(root) {
  if (root === null) {
    return null;
  }

  let head = null;

  function convert(node) {
    if (node === null) {
      return null;
    }

    convert(node.right);

    let doublyNode = new NodeDoubly(node.data);

    if (head === null || head.data > node.data) {
      doublyNode.next = head;
      if (head !== null) {
        head.prev = doublyNode;
      }
      head = doublyNode;
    } else {
      let current = head;
      while (current.next !== null && current.next.data < node.data) {
        current = current.next;
      }

      doublyNode.next = current.next;
      if (current.next !== null) {
        current.next.prev = doublyNode;
      }
      current.next = doublyNode;
      doublyNode.prev = current;
    }

    convert(node.left);
  }

  convert(root);
  head.prev = null;

  return head;
}

This function starts by checking if the root of the binary tree is null. If it is, then the function returns null.

Then, it sets the head of the doubly linked list to null.

The convert function is a recursive function that converts a binary tree node into a doubly linked list node.

The base case for the recursion is when the node is null. In this case, the function returns null.

The recursion converts the right child of the node, then creates a new doubly linked list node for the node, then converts the left child of the node.

Finally, it sets the next and previous pointers of the doubly linked list node.

The main function calls the convert function with the root of the binary tree as its argument, and then sets the previous pointer of the head of the doubly linked list to null.

Finally, it returns the head of the doubly linked list.