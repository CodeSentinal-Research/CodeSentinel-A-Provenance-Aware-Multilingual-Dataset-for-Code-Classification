Here is a JavaScript code snippet that implements the solution for the problem. The code uses a while loop to iterate through the linked list, and then swaps the 'next' and 'prev' pointers for each node.

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
    }

    reverse() {
        if (!this.head) {
            return;
        }

        let current = this.head;

        while (current) {
            let temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev;
        }

        if (temp) {
            this.head = temp.prev;
        }
    }

    // Method to insert a node at the end of the list
    insert(data) {
        let node = new Node(data);

        if (!this.head) {
            this.head = node;
            this.head.next = this.head;
            this.head.prev = this.head;
        } else {
            let current = this.head;
            while (current.next !== this.head) {
                current = current.next;
            }
            current.next = node;
            node.prev = current;
            node.next = this.head;
            this.head.prev = node;
        }
    }

    printList() {
        let current = this.head;
        let result = '';
        do {
            result += current.data + ' ';
            current = current.next;
        } while (current !== this.head);
        console.log(result);
    }
}

To use the code, you create a new DoublyLinkedList and insert nodes, then call the reverse method:

let list = new DoublyLinkedList();
list.insert(1);
list.insert(2);
list.insert(3);
list.insert(4);
list.insert(5);

list.printList(); // Outputs: 1 2 3 4 5 

list.reverse();

list.printList(); // Outputs: 5 4 3 2 1 

This code assumes that the input data is integers.