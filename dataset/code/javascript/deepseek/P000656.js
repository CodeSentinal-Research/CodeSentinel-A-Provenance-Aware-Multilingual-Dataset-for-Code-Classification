Here is the JavaScript code for your problem.

class Node {
  constructor(data, next = null, bottom = null) {
    this.data = data;
    this.next = next;
    this.bottom = bottom;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  addNode(data) {
    const newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
  }

  flatten() {
    if (!this.head) {
      return null;
    }

    let prev = new Node(0);
    let newHead = prev;
    let current = this.head;
    let nextNodes = this.head.bottom;

    while (current) {
      if (!nextNodes) {
        this.tail = current;
        current = current.next;
        nextNodes = current ? current.bottom : null;
      } else {
        if (current.data < nextNodes.data) {
          prev.bottom = current;
          prev = current;
        } else {
          temp = new Node(nextNodes.data);
          temp.bottom = current.bottom;
          prev.bottom = temp;
          prev = temp;
        }
        current = current.next;
        nextNodes = nextNodes.bottom;
      }
    }

    this.head = newHead.bottom;
    return this.head;
  }
}

In this code, we first define a `Node` class with three properties: `data`, `next`, and `bottom`. Then we define a `LinkedList` class with a `head` and a `tail` property.

In the `LinkedList` class, we define an `addNode` method to add a new node to the list. We also define a `flatten` method to flatten the list into a new sorted list.

In the `flatten` method, we first initialize `prev`, `newHead`, `current`, and `nextNodes` to the first node of the new list, null, and the next node of the head node. Then we enter a while loop, and inside this loop, we check if there are no more nodes left to process. If there are, we simply return null.

Otherwise, we enter a while loop again. Inside this loop, we check if there are no more nodes in the next pointer of the current node. If there are, we simply move `current` to the next node. If not, we enter another while loop, checking if the current node's data is less than the next node's data. If it is, we add the current node to the previous node's bottom pointer. If it's not, we create a new node with the next node's data, set its bottom pointer to the current node's bottom pointer, and add it to the previous node's bottom pointer. Then we move `current` and `nextNodes` to their next nodes and next pointers.

Finally, we set the head of the list to the bottom of the new list, and return the new head of the list.