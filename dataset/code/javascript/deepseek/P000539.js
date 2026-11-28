class Queue {
    constructor() {
        this.queue = [];
        this.counts = {};
    }

    add(value) {
        if (!this.counts[value]) {
            this.queue.push(value);
            this.counts[value] = 1;
        } else {
            this.counts[value]++;
        }
    }

    showFirstUnique() {
        while(this.queue.length > 0) {
            let item = this.queue.shift();
            if(this.counts[item] === 1) {
                return item;
            } else {
                this.counts[item]++;
            }
        }
        return -1;
    }
}

function processOperations(n, arr, q) {
    let queue = new Queue();

    for(let i = 0; i < n; i++) {
        queue.add(arr[i]);
        console.log(queue.showFirstUnique());
    }

    for(let j = 0; j < q; j++) {
        queue = new Queue();
        for(let k = 0; k < n; k++) {
            queue.add(arr[k]);
        }
        console.log(queue.showFirstUnique());
    }
}

processOperations(5, [1, 2, 3, 2, 1], 2);

In this code, a custom Queue data structure is defined, which maintains a queue of integers and allows for operations: 

- add(value): Add an integer to the end of the queue.
- showFirstUnique(): Return the first unique integer in the queue. If no unique integer exists, return -1.

In the processOperations function, the queue data structure is used to process a sequence of operations. It accepts an integer n, an array arr of n integers, and an integer q, representing the number of operations. It then creates a new queue and processes the operations, printing the result for every showFirstUnique() operation.

This code is written in JavaScript and should work in any modern web browser or node.js environment.