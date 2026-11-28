Here is the JavaScript code to solve the given problem:

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  findMin() {
    if(this.head === null) {
      return -1;
    }

    let current = this.head;
    let min = current.data;

    while(current !== null) {
      if(current.data < min) {
        min = current.data;
      }
      current = current.next;
    }

    return min;
  }

  insert(data) {
    let newNode = new Node(data);

    if(this.head === null) {
      this.head = newNode;
    } else {
      let current = this.head;

      while(current.next !== null) {
        current = current.next;
      }

      current.next = newNode;
    }
  }
}


The `LinkedList` class has an `insert` method that creates new nodes, and a `findMin` method that iterates through the list to find the minimum value. If the list is empty, it returns -1.

The `insert` method initializes a new node with the given data, then if the list is empty it sets the head of the list to the new node, otherwise it iterates through the list until it reaches the last node and sets the next of the last node to the new node.

The `findMin` method starts by checking if the list is empty. If it is, it returns -1. Then it sets the minimum value to the data of the first node and iterates through the list, checking if each data is less than the current minimum. If it is, it updates the minimum. Finally, it returns the minimum value.