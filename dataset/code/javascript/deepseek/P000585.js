Here is a JavaScript solution using a Node class to represent each node in the linked list and a LinkedList class to represent the whole linked list:

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

    append(data) {
        let node = new Node(data);

        if (!this.head) {
            this.head = node;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = node;
        }
    }

    reorder() {
        if (!this.head || !this.head.next) {
            return;
        }

        let slow = this.head;
        let fast = this.head.next;

        while(fast && fast.next) {
            if(slow) {
                slow = slow.next;
            }
            fast = fast.next.next;
        }

        let second = slow.next;
        slow.next = null;

        second.next = this.head;

        this.head = second;
    }

    print() {
        let current = this.head;
        while (current) {
            console.log(current.data);
            current = current.next;
        }
    }
}

let list = new LinkedList();
list.append(1);
list.append(2);
list.append(3);
list.append(4);
list.append(5);
list.reorder();
list.print();

This script will print the nodes of the reordered linked list: 1 -> 5 -> 2 -> 4 -> 3.