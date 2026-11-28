Here is a JavaScript solution for the problem using a simple linked list structure.

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    add(data) {
        const newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    getNode(index) {
        let current = this.head;
        for (let i = 0; i < index; i++) {
            if (current.next === null) {
                return null;
            }
            current = current.next;
        }
        return current;
    }

    removeNode(node) {
        if (this.head === node && this.tail === node) {
            this.head = null;
            this.tail = null;
        } else if (this.head === node) {
            this.head = node.next;
        } else if (this.tail === node) {
            let current = this.head;
            while (current.next !== this.tail) {
                if (current.next === this.tail) {
                    current.next = null;
                }
                current = current.next;
            }
            this.tail = current;
        } else {
            let prev = node.next;
            node.next = null;
            prev.next = node.next;
        }
    }
}

class BrowserTabsManager {
    constructor() {
        this.tabs = new LinkedList();
        this.tabs.add(0);
        this.currentIndex = 0;
    }

    open(url) {
        this.tabs.add(url);
        this.currentIndex = this.tabs.head.data;
    }

    close(index) {
        let node = this.tabs.getNode(index);
        if (node !== null) {
            this.tabs.removeNode(node);
            if (this.tabs.head === null) {
                this.currentIndex = -1;
            }
        }
    }

    switch(index) {
        if (this.tabs.head !== null && this.currentIndex !== index) {
            this.currentIndex = index;
        }
    }

    moveLeft(index) {
        if (index >= 0 && this.tabs.getNode(index) !== null) {
            this.tabs.removeNode(this.tabs.getNode(index));
            this.tabs.add(index);
            this.currentIndex = index;
        }
    }

    moveRight(index) {
        if (index >= 0 && this.tabs.getNode(index) !== null) {
            this.tabs.removeNode(this.tabs.getNode(index));
            this.tabs.add(index, this.currentIndex);
            this.currentIndex = index;
        }
    }

    current() {
        return this.tabs.getNode(this.currentIndex).data;
    }
}

This code creates a linked list to simulate a browser tab, and provides methods to manage these tabs. It uses a Node class to create individual tab objects, and a LinkedList class to manage them. The BrowserTabsManager class is used to manage these operations. The methods are efficient because they only traverse the list once for each operation.