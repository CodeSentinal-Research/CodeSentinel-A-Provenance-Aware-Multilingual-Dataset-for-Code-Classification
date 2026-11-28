Here is the JavaScript solution using a circular linked list:

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class CircularLinkedList {
  constructor() {
    this.head = null;
  }

  insert(data) {
    const newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      this.head.next = newNode;
    } else {
      let temp = this.head;
      while (temp.next != this.head) {
        temp = temp.next;
      }
      temp.next = newNode;
      newNode.next = this.head;
    }
  }

  remove() {
    if (this.head == null) return;
    let temp = this.head;
    while (temp.next != this.head) {
      temp = temp.next;
    }
    temp.next = null;
  }
}

function josephus(n, k) {
  if (n === 0) return -1;

  const list = new CircularLinkedList();
  for (let i = 1; i <= n; i++) {
    list.insert(i);
  }

  let eliminated = null;
  list.head.data = 0;

  while (n > 1) {
    for (let i = 1; i < k; i++) {
      list.head = list.head.next;
    }

    eliminated = list.head.data;
    list.remove();
    n--;
    console.log(`Remaining person: ${eliminated}`);
  }

  return list.head.data;
}

This code first builds a circular linked list with `n` people, then runs the Josephus problem until only one person remains. In each iteration, it removes the `k-th` person and labels the remaining person as the survivor. The function `josephus` runs the simulation, with `n` and `k` as input, and returns the label of the survivor.

Please note that this code doesn't handle invalid inputs, it's a basic implementation of a circular linked list and a possible solution to the Josephus problem. In a real-world scenario, you'd want to add error checking and handle edge cases.