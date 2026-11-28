Sure, here is a JavaScript code that implements the task. It uses a LinkedList data structure to implement the linked list and Node objects to store each node in the linked list.

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

  appendNode(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = newNode;
    }
  }
}

function reverseEvenLengthGroups(n) {
  let linkedList = new LinkedList();
  for (let i = 1; i <= n; i++) {
    linkedList.appendNode(i);
  }

  let current = linkedList.head;
  while (current) {
    let groupSize = 1;
    while (current && groupSize < 50 && current.next) {
      current = current.next;
      groupSize++;
    }
    if (groupSize % 2 === 0) {
      let prev = null;
      let current1 = current;
      let current2 = current1.next;
      while (prev !== current1) {
        [current1.data, current2.data] = [current2.data, current1.data];
        prev = current1;
        current1 = current2;
        if (current2) {
          current2 = current2.next;
        }
      }
      let temp = current;
      current = current.next;
      temp.next = current;
    } else {
      current = current.next;
    }
  }

  return linkedList.head;
}

In this code, we first initialize a linked list with `n` nodes, then iterate through the linked list and reverse every second group of size 50 or less. We use three pointers to traverse the linked list: `prev`, `current`, and `current2`. `Prev` is used to keep track of the previous node in the group, `current` is used to traverse the current group, and `current2` is used to traverse the next node in the group. When we find a group of size 50 or less, we reverse the group by swapping the data of the first and last node, then update `prev`, `current`, and `current2`. After reversing the group, we set the `next` of the last node to the reversed group and update `current` to `current.next`. This way, the reversed group is the last node in the list, and the remaining nodes in the list form the next group.