Sure, here is the JavaScript code that fulfills the requirements:

class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class LinkedList {
  constructor(head = null) {
    this.head = head;
  }

  append(data) {
    if (!this.head) {
      this.head = new Node(data);
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = new Node(data);
    }
  }

  reverseGroups(groups) {
    let current = this.head;
    let newList = new LinkedList();
    let prev = null;
    while (current) {
      let groupSize = groups[this.index];
      let end = current;
      for (let i = 0; i < groupSize && end; i++) {
        end = end.next;
      }
      let next = end ? end.next : null;
      end ? (end.next = null) : (current = null);
      if (prev) prev.next = current;
      prev = newList.append(this.cutEnd(groupSize));
    }
    return newList.head;
  }

  cutEnd(n) {
    let current = this.head;
    while (n-- > 1 && current) {
      current = current.next;
    }
    let next = current ? current.next : null;
    if (current) current.next = null;
    return next;
  }

  index = 0;
}

function solve(n, list, g, groups) {
  let linkedList = new LinkedList();
  for (let i = 1; i <= n; i++) {
    linkedList.append(i);
  }
  return linkedList.reverseGroups(groups);
}

// Test with provided example:
let list = new LinkedList();
list.append(1);
list.append(2);
list.append(3);
list.append(4);
list.append(5);

let groups = [2, 3, 1];
console.log(solve(5, list, 2, groups));

This code defines a `LinkedList` class with methods to append nodes and to reverse the nodes in groups according to the provided group sizes. It also provides a `reverseGroups` method for reversing the linked list. The `solve` function is used to create a linked list from 1 to `n`, then call `reverseGroups` on it, with the provided group sizes.