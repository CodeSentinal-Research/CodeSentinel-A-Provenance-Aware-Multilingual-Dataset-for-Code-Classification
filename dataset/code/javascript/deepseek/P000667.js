Here is a simple implementation of a Circular Deque using a doubly linked list in JavaScript. The deque contains methods for insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, and size.

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

class CircularDeque {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  insertFront(data) {
    let node = new Node(data);
    if (this.size === 0) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
    this.size++;
  }

  insertLast(data) {
    let node = new Node(data);
    if (this.size === 0) {
      this.head = node;
      this.tail = node;
    } else {
      node.prev = this.tail;
      this.tail.next = node;
      this.tail = node;
    }
    this.size++;
  }

  deleteFront() {
    if (this.size === 0) {
      console.log("Deque is empty");
      return;
    }
    console.log(this.head.data);
    this.head = this.head.next;
    this.tail.next = this.head;
    this.head.prev = this.tail;
    this.size--;
  }

  deleteLast() {
    if (this.size === 0) {
      console.log("Deque is empty");
      return;
    }
    console.log(this.tail.data);
    this.tail = this.tail.prev;
    this.tail.next = this.head;
    this.head.prev = this.tail;
    this.size--;
  }

  getFront() {
    if (this.size === 0) {
      console.log("Deque is empty");
      return;
    }
    console.log(this.head.data);
  }

  getRear() {
    if (this.size === 0) {
      console.log("Deque is empty");
      return;
    }
    console.log(this.tail.data);
  }

  isEmpty() {
    if (this.size === 0) {
      console.log("Deque is empty");
    } else {
      console.log("Deque is not empty");
    }
  }

  size() {
    console.log(this.size);
  }
}

// Use the code below for input handling
let deque = new CircularDeque();
let operations = [
  [1, 1, "value1"],
  [2, 1, "value2"],
  [3, 2, "value3"],
  [4, 2, "value4"],
  [5, 1, "value5"],
  [6, 3, "value6"],
  [7, 1, "value7"],
];

for (let op of operations) {
  switch (op[0]) {
    case 1:
      deque.insertFront(op[2]);
      break;
    case 2:
      deque.insertLast(op[2]);
      break;
    case 3:
      deque.deleteFront();
      break;
    case 4:
      deque.deleteLast();
      break;
    case 5:
      deque.getFront();
      break;
    case 6:
      deque.getRear();
      break;
    case 7:
      deque.isEmpty();
      break;
  }
}

This code will create a CircularDeque object and a list of operations. It then iterates through the operations list, executing each operation based on its type.