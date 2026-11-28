Here is a basic implementation of a Skip List data structure in JavaScript:

class Node {
    constructor(height = 1, value = null, left = null, right = null) {
        this.height = height;
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class SkipList {
    constructor() {
        this.head = new Node();
    }

    randomHeight() {
        let height = 1;
        while (Math.random() < 0.5 && Math.random() < 0.5) height++;
        return height;
    }

    add(value) {
        let node = new Node(this.randomHeight(), value);

        let prev = [];
        let curr = this.head;

        while (true) {
            if (curr.left && curr.left.value >= value) curr = curr.left;
            else if (curr.right && curr.right.value >= value) curr = curr.right;
            else break;
            prev.push(curr);
        }

        let newNode = new Node(this.randomHeight(), value, prev[prev.length - 1].right, node);
        prev[prev.length - 1].right = newNode;

        while (prev.length < node.height) {
            prev.push(new Node(this.randomHeight(), null, null, prev[prev.length - 1]));
        }
    }

    search(value) {
        let curr = this.head;

        while (curr && curr.value !== value) {
            curr = curr.right && curr.right.value >= value ? curr.right : curr.left;
        }

        return curr !== null;
    }

    erase(value) {
        let curr = this.head;

        while (curr && curr.value !== value) {
            curr = curr.right && curr.right.value >= value ? curr.right : curr.left;
        }

        if (!curr) return false;

        while (curr.left) {
            curr.left.value = curr.value;
            curr = curr.left;
        }

        while (prev.length < curr.height) {
            prev.push(new Node(this.randomHeight(), null, null, curr));
        }

        curr.right = curr.right && curr.right.value >= value ? curr.right : curr.left;

        return true;
    }
}

This code first defines the Node class, which will be our nodes in the Skip List. Each node stores the value and pointers to the left and right neighbors in the list.

The SkipList class defines the methods to add a node, search for a value, and erase a value. In the add() method, we create a new node with a random height. In the search() method, we traverse the list to find the target value. In the erase() method, we find the target value and remove it from the list.

Please note that this is a very basic implementation and does not handle all edge cases. For example, it does not handle deletion of multiple values or when the list is empty. Also, this code does not handle concurrent operations and does not use a random seed to shuffle the list when adding new values.

For handling concurrent operations, you would likely need a more complex data structure such as a Red-Black Tree or a BST and concurrency primitives such as locks or other concurrency mechanisms in JavaScript.