Here is the JavaScript code that fulfills your requirements:

class Node {
    constructor(data, next) {
        this.data = data;
        this.next = next;
    }
}

class CircularLinkedList {
    constructor() {
        this.head = null;
    }
    
    append(data) {
        let node = new Node(data);
        if(!this.head) {
            this.head = node;
            this.head.next = this.head;
        } else {
            let cur = this.head;
            while(cur.next != this.head) {
                cur = cur.next;
            }
            cur.next = node;
            node.next = this.head;
        }
    }
    
    insert(data, insertVal) {
        if(!this.head) {
            this.head = new Node(insertVal);
            this.head.next = this.head;
        } else if (data < this.head.data) {
            if(data > insertVal) {
                let cur = this.head;
                while(cur.next != this.head && cur.next.data < insertVal) {
                    cur = cur.next;
                }
                if(cur.next.data > insertVal) {
                    cur.next = new Node(insertVal);
                    cur.next.next = this.head;
                } else {
                    let newNode = new Node(insertVal);
                    newNode.next = cur.next;
                    cur.next = newNode;
                }
            } else {
                let cur = this.head;
                while(cur.data < data && cur.next.data < insertVal) {
                    cur = cur.next;
                }
                if(cur.data > insertVal) {
                    cur.next = new Node(insertVal);
                    cur.next.next = this.head;
                } else {
                    let newNode = new Node(insertVal);
                    newNode.next = cur.next;
                    cur.next = newNode;
                }
            }
        } else {
            if(data > insertVal) {
                let cur = this.head;
                while(cur.next.data < insertVal) {
                    cur = cur.next;
                }
                if(cur.next.data > insertVal) {
                    cur.next = new Node(insertVal);
                    cur.next.next = this.head;
                } else {
                    let newNode = new Node(insertVal);
                    newNode.next = cur.next;
                    cur.next = newNode;
                }
            } else {
                let cur = this.head;
                while(cur.data < data && cur.next.data < insertVal) {
                    cur = cur.next;
                }
                if(cur.data > insertVal) {
                    cur.next = new Node(insertVal);
                    cur.next.next = this.head;
                } else {
                    let newNode = new Node(insertVal);
                    newNode.next = cur.next;
                    cur.next = newNode;
                }
            }
        }
        return this.head;
    }
}

This code defines a `Node` class for the nodes in the circular linked list and a `CircularLinkedList` class for the linked list itself. The `append` method is used to add a new node to the list. The `insert` method is used to insert a new node with the given value into the list while maintaining the sorted order. The `data` and `insertVal` are the input parameters to the methods.