Here's the JavaScript code for the problem:

class Node {
  constructor(data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  addNode(data) {
    let newNode = new Node(data);

    if (this.head === null) {
      this.head = this.tail = newNode;
    } else {
      newNode.prev = this.tail;
      this.tail.next = newNode;
      this.tail = newNode;
    }
  }

  reverse() {
    let temp = null;
    let current = this.head;

    while (current !== null) {
      temp = current.prev;
      current.prev = current.next;
      current.next = temp;
      current = current.prev;
    }

    if (temp !== null) {
      this.head = temp.prev;
    }
  }

  isBitonic(start, end) {
    Node *l = start;
    Node *r = start;
    bool isBitonic = true;

    while (r !== end) {
      if (l->data < r->data) {
        l = l->next;
      } else {
        r = r->next;
        isBitonic = false;
      }
    }

    return isBitonic;
  }

  mergeSortAndReverse(start, end) {
    if (!this.isBitonic(start, end)) {
      this.reverse();
      this.mergeSort(start, end);
      this.reverse();
    }
  }

  mergeSort(start, end) {
    if (end !== start) {
      let mid = start;
      Node *l = start;
      Node *r = end;
      Node *midPrev = null;

      while (l !== r) {
        midPrev = mid;
        mid = this.split(mid, mid->next, r);
      }

      this.mergeSort(start, midPrev);
      this.mergeSort(mid, end);
    }
  }

  split(l, r, end) {
    Node *pre = l;
    Node *cur = l->next;
    Node *post = r;

    while (cur !== end) {
      if (r->data < l->data) {
        pre = cur;
        cur = cur->next;
      } else {
        post = cur->next;
        this.merge(l, cur, post);
      }
    }

    return l;
  }

  merge(l, cur, r) {
    l->next = r;
    r->prev = l;
    cur->prev = l;
    l->next = cur;
  }

  sort(start) {
    this.mergeSortAndReverse(start, this.tail);
  }
}

let list = new DoublyLinkedList();
list.addNode(5);
list.addNode(6);
list.addNode(3);
list.addNode(7);
list.addNode(8);
list.addNode(10);
list.addNode(1);
list.addNode(2);
list.addNode(4);
list.sort(list.head);

let current = list.head;
while (current !== null) {
  console.log(current.data);
  current = current.next;
}

This code creates a doubly linked list, populates it with some values, sorts the list, and then prints the sorted values. The `sort()` method is the main method that sorts the list using merge sort and reverse technique. The merge sort is used because it's a standard technique for sorting linked lists. The reverse operation is used to revert the list back to its original order.