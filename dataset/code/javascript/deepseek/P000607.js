Here is a JavaScript solution for the LFU Cache problem:

class Node {
    constructor(key, val, freq) {
        this.key = key;
        this.val = val;
        this.freq = freq;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    insert(node) {
        if (this.head === null) {
            this.head = node;
            this.tail = node;
        } else {
            node.prev = this.tail;
            this.tail.next = node;
            this.tail = node;
        }
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
    }
}

class LFUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.map = new Map();
        this.list = new DoublyLinkedList();
    }

    get(key) {
        if (!this.map.has(key)) {
            return -1;
        }

        const node = this.map.get(key);
        this.list.remove(node);
        node.freq += 1;
        this.list.insert(node);
        return node.val;
    }

    put(key, value) {
        if (this.capacity <= 0) {
            return;
        }

        if (this.map.has(key)) {
            const node = this.map.get(key);
            this.list.remove(node);
            node.val = value;
            node.freq += 1;
            this.list.insert(node);
        } else {
            if (this.map.size === this.capacity) {
                const leastFrequentNode = this.list.head;
                this.map.delete(leastFrequentNode.key);
                this.list.remove(leastFrequentNode);
            }

            const node = new Node(key, value, 1);
            this.map.set(key, node);
            this.list.insert(node);
        }
    }
}

This solution uses a Map to quickly look up the key and a DoublyLinkedList to keep track of the least frequent nodes. The DoublyLinkedList is doubly linked with two pointers in each node to easily remove and insert nodes.

The time complexity is O(1) for the get and put operations, since both operations use the Map and DoublyLinkedList. The space complexity is O(capacity), where capacity is the capacity of the LFU cache.