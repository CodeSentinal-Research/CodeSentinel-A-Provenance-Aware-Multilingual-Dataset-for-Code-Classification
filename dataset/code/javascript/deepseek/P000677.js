Here is the JavaScript solution for the given problem. This solution uses a doubly-linked list (a kind of linked list where each node contains a reference to the previous node and the next node in the list) and a hashtable (a way to map keys to values) to implement an ordered dictionary.

class Node {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    add(node) {
        if (this.head === null) {
            this.head = node;
            this.tail = this.head;
        } else {
            node.prev = this.tail;
            this.tail.next = node;
            this.tail = node;
        }
        this.size++;
    }

    remove(node) {
        if (node.prev !== null) {
            node.prev.next = node.next;
        } else {
            this.head = node.next;
        }
        if (node.next !== null) {
            node.next.prev = node.prev;
        } else {
            this.tail = node.prev;
        }
        this.size--;
    }

    removeAll() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
}

class OrderedDictionary {
    constructor() {
        this.dict = new Map();
        this.list = new DoublyLinkedList();
    }

    put(key, value) {
        if (this.dict.has(key)) {
            this.list.remove(this.dict.get(key));
        }
        let node = new Node(key, value);
        this.dict.set(key, node);
        this.list.add(node);
    }

    get(key) {
        let node = this.dict.get(key);
        return node ? node.value : null;
    }

    remove(key) {
        let node = this.dict.get(key);
        if (node) {
            this.list.remove(node);
            this.dict.delete(key);
        }
    }

    firstKey() {
        return this.list.head ? this.list.head.key : null;
    }

    lastKey() {
        return this.list.tail ? this.list.tail.key : null;
    }

    nextKey(key) {
        let node = this.dict.get(key);
        if (node) {
            return node.next ? node.next.key : null;
        }
        return null;
    }

    previousKey(key) {
        let node = this.dict.get(key);
        if (node) {
            return node.prev ? node.prev.key : null;
        }
        return null;
    }
}

The above code defines the required classes and functions. The `OrderedDictionary` class wraps around a doubly-linked list and a map (a kind of hash table). The map is used to map keys to nodes in the list, and each node contains a key, a value, and a reference to the previous and next nodes.

The `put`, `get`, `remove`, `firstKey`, `lastKey`, `nextKey`, and `previousKey` methods are used to perform the operations on the ordered dictionary.

The `removeAll` method is used to clear the dictionary and list.

The `DoublyLinkedList` class provides methods for adding and removing nodes, and for removing all nodes.

The `Node` class is a simple node structure.

You can process a sequence of operations and print the results of query operations by creating an instance of the `OrderedDictionary` class and calling the required methods.