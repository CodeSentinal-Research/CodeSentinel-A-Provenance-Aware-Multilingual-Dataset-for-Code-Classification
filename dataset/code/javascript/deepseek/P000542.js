Here is the JavaScript code for the problem:

class Queue {
    constructor() {
        this.data = [];
    }

    pushFront(x) {
        this.data.unshift(x);
    }

    pushMiddle(x) {
        this.data.splice(Math.floor((this.data.length - 1) / 2), 0, x);
    }

    pushBack(x) {
        this.data.push(x);
    }

    popFront() {
        if(this.data.length === 0) {
            return -1;
        }
        return this.data.shift();
    }

    popMiddle() {
        if(this.data.length === 0) {
            return -1;
        }
        return this.data.splice(Math.floor((this.data.length - 1) / 2), 1)[0];
    }

    popBack() {
        if(this.data.length === 0) {
            return -1;
        }
        return this.data.pop();
    }
}

function processQueue(q, operations) {
    const queue = new Queue();
    for(let i = 0; i < q; i++) {
        queue.pushBack(i + 1);
    }

    let result = [];
    while(operations-- > 0) {
        const operation = operations % 4;
        if(operation === 0) {
            result.push(queue.popFront());
        } else if(operation === 1) {
            result.push(queue.popMiddle());
        } else if(operation === 2) {
            result.push(queue.popBack());
        } else {
            result.push(queue.pushBack(operations + 1));
        }
    }

    console.log(result.join(' '));
}

In this code, we create a Queue class that includes methods for each operation (pushFront, pushMiddle, pushBack, popFront, popMiddle, popBack). In the `processQueue` function, we create a new Queue, add elements from 1 to `q` to the queue, and then process each operation in the `operations` times. The results are stored in an array, and they are printed out in the end.

Please note that the `popFront` and `popMiddle` operations remove elements from both ends of the queue. The `popBack` operation removes an element from the end of the queue. The `pushBack` operation adds an element to the end of the queue. The `pushFront` and `pushMiddle` operations add elements to the front or the middle of the queue, respectively.