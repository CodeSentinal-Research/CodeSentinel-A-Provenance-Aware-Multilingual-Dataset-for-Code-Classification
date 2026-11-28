Here is the JavaScript code to solve the problem:

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(data) {
        var newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            newNode.prev = this.tail;
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }
}

function rotateDoublyLinkedList(n, k) {
    if (n === 0) return;

    let list = new DoublyLinkedList();
    for (let i = 1; i <= n; i++) {
        list.append(i);
    }

    let head = list.head;
    let tail = list.tail;

    tail.next = head;
    head.prev = tail;

    k = k % n;

    while (k-- > 0) {
        tail = tail.prev;
    }

    list.head = tail.prev;

    return list.head;
}

In this code, we first define a Node class and a DoublyLinkedList class. The DoublyLinkedList class has a method to append nodes to the list, and the Node class has a constructor that initializes data, next, and prev.

Then we define the `rotateDoublyLinkedList` function which takes in the total number of nodes `n` and the number of rotations `k`. It first checks if `n` is 0, if so, it simply returns as no rotation is needed.

If `n` is not 0, we create a new DoublyLinkedList and append nodes from 1 to `n` to the list.

We then set `head` and `tail` of the list to the last node of the list, and we change the `next` and `prev` of the `tail` to move it to the start of the list.

Then, we rotate the list by moving `tail` k times and adjusting the `next` and `prev` of `tail`. Finally, we set the `next` of the new head to the `prev` of the old head, and the `prev` of the new head to the `next` of the old head.

The result is the new head of the rotated doubly linked list.