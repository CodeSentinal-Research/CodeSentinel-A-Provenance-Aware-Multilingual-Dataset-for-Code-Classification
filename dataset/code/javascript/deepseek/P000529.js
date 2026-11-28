class Queue {
    constructor(capacity) {
        this.data = [];
        this.head = 0;
        this.tail = -1;
        this.capacity = capacity;
    }

    isFull() {
        return this.tail + 1 === this.head || (this.tail === this.capacity - 1 && this.head === 0)
    }

    isEmpty() {
        return this.tail === -1 || this.head === this.tail + 1;
    }

    enqueue(x) {
        if (!this.isFull()) {
            this.tail = (this.tail + 1) % this.capacity;
            this.data[this.tail] = x;
        } else {
            console.log('Queue is full!');
        }
    }

    dequeue() {
        if (!this.isEmpty()) {
            const result = this.data[this.head];
            this.head = (this.head + 1) % this.capacity;
            if (this.head === this.tail + 1) {
                this.tail = -1;
            }
            return result;
        } else {
            console.log('Queue is empty!');
        }
    }

    front() {
        if (!this.isEmpty()) {
            return this.data[this.head];
        } else {
            console.log('Queue is empty!');
        }
    }
}

const queue = new Queue(5);

let nextLine;
while ((nextLine = readline()) != null) {
    const [operation, ...params] = nextLine.split(' ');

    switch (operation) {
        case 'enqueue':
            queue.enqueue(Number(params[0]));
            break;
        case 'dequeue':
            console.log(queue.dequeue());
            break;
        case 'front':
            console.log(queue.front());
            break;
        case 'isEmpty':
            console.log(queue.isEmpty() ? 'true' : 'false');
            break;
        case 'isFull':
            console.log(queue.isFull() ? 'true' : 'false');
            break;
    }
}