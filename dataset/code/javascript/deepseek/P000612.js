Here is the JavaScript code for your problem. This code uses the Euclidean algorithm to calculate the greatest common divisor (GCD) between two numbers and a recursive approach to insert nodes in the linked list.

class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insertNode(value) {
        let node = new Node(value);
        if (this.head === null) {
            this.head = node;
        } else {
            let current = this.head;
            while (current.next !== null) {
                current = current.next;
            }
            current.next = node;
        }
        return this.head;
    }

    gcd(a, b) {
        if (!b) {
            return a;
        }
        return this.gcd(b, a % b);
    }

    insertAndComputeGCD() {
        if (!this.head || !this.head.next) {
            return this.head;
        }
        let current = this.head;
        while (current !== null) {
            let nextValue = current.next.value;
            let currentValue = current.value;
            let gcd = this.gcd(currentValue, nextValue);
            current.next.value = gcd;
            current = current.next;
        }
        return this.head;
    }
}

To use the code, you can create a LinkedList object and call the `insertAndComputeGCD` method to insert the new nodes and compute the GCD.

let list = new LinkedList();
list.insertNode(10);
list.insertNode(20);
list.insertNode(30);
list.insertNode(40);
list.insertAndComputeGCD();

In this example, the GCD of 10 and 20 is 10, of 20 and 30 is 10, and so on. This is done recursively until there are no more nodes to process.