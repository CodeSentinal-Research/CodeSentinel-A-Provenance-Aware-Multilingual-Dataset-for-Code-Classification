class LRUCache {
    constructor(capacity) {
        this.map = new Map();
        this.queue = new DoublyLinkedList();
        this.capacity = capacity;
    }
    
    get(key) {
        if (!this.map.has(key)) {
            return -1;
        }
        let node = this.map.get(key);
        this.queue.remove(node);
        node.value = node.value;
        this.queue.push(node);
        return node.value;
    }
    
    put(key, value) {
        if (this.get(key) !== -1) {
            this.map.get(key).value = value;
        } else {
            if (this.map.size === this.capacity) {
                let node = this.queue.removeLast();
                this.map.delete(node.key);
            }
            let node = new DoublyLinkedListNode(key, value);
            this.map.set(key, node);
            this.queue.push(node);
        }
    }
}

class DoublyLinkedListNode {
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
    }
    
    remove(node) {
        if (node.prev) {
            node.prev.next = node.next;
        } else {
            this.head = node.next;
        }
        
        if (node.next) {
            node.next.prev = node.prev;
        } else {
            this.tail = node.prev;
        }
        
        node.prev = null;
        node.next = null;
    }
    
    push(node) {
        if (!this.head) {
            this.head = node;
            this.tail = node;
        } else {
            node.prev = this.tail;
            this.tail.next = node;
            this.tail = node;
        }
    }
    
    removeLast() {
        let node = this.tail;
        this.tail = node.prev;
        this.tail.next = null;
        return node;
    }
}