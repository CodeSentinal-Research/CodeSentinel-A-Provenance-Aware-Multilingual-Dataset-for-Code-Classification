class Node {
    constructor(data, next = null, child = null) {
        this.data = data;
        this.next = next;
        this.child = child;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }
    
    append(data) {
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
        return this.head;
    }
    
    flatten() {
        let dummy = new Node(0);
        let prev = dummy;
        let stack = [];
        let current = this.head;
        
        while (current || stack.length) {
            while (current) {
                stack.push(current);
                current = current.child;
            }
            
            let top = stack.pop();
            prev.next = top;
            prev = top;
            current = top.next;
        }
        
        this.head = dummy.next;
    }
}

This JavaScript code defines a `Node` class and a `LinkedList` class. The `Node` class represents a node in the linked list. Each node has `data`, `next`, and `child` properties. The `LinkedList` class represents the linked list itself. The `LinkedList` class has a `head` property to store the head of the linked list. 

The `append` method appends a new node with the given data to the end of the linked list. The `flatten` method flattens the linked list. It uses a stack to achieve this. The current node is popped out of the stack and its child is pushed into the stack. If there is no child left for the current node, the current node is popped out and the previous node is linked to the current node. The process repeats until the stack is empty. The head of the flattened linked list is set as the new head of the linked list.