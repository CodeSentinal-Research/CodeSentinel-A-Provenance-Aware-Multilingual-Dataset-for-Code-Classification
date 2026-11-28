class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class Queue {
    constructor() {
        this.front = this.rear = null;
        this.size = 0;
    }

    isEmpty() {
        return this.size == 0;
    }

    enqueue(data) {
        let node = new Node(data);
        if (this.isEmpty()) {
            this.front = this.rear = node;
        } else {
            this.rear.next = node;
            this.rear = node;
        }
        this.size++;
    }

    dequeue() {
        if (this.isEmpty()) {
            return "Underflow";
        }
        let temp = this.front;
        this.front = this.front.next;
        this.size--;
        if (this.isEmpty()) {
            this.rear = null;
        }
        return temp.data;
    }

    front() {
        if (this.isEmpty()) {
            return "No elements in Queue";
        }
        return this.front.data;
    }

    size() {
        return this.size;
    }
}

let queue = new Queue();
let queries = [5, 6, 7, 3, 1, 2, 4, 2, 0];

queries.forEach(query => {
    queue.enqueue(query);
    console.log('enqueue ' + query + ':', queue.front(), queue.size(), queue.isEmpty());
});

for(let i = 0; i < queries.length; i++){
    console.log('dequeue:', queue.dequeue());
    console.log('Front:', queue.front());
    console.log('Size:', queue.size());
    console.log('Is Empty:', queue.isEmpty());
}