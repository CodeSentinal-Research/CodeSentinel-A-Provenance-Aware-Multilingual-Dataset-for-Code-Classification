Sure, here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs = line.split(' ').map(Number);
    getMaxInWindows();
}).on('close', () => {
    process.stdin.close();
    getMaxInWindows();
});

function getMaxInWindows() {
    let n = inputs[0], k = inputs[1], arr = inputs.slice(2);
    if (n < 1 || n > 200000 || k < 1 || k > n || arr.length !== n) {
        return console.log('Invalid inputs');
    }

    let maxHeap = new MaxHeap(), res = [];
    for (let i = 0; i < n; i++) {
        maxHeap.insert(arr[i]);
        maxHeap.max() && res.push(maxHeap.max().element);
        maxHeap.extractMax();
    }

    console.log(res.join(' '));
}

class MaxHeap {
    constructor() {
        this.heap = [];
    }

    parent(i) { return Math.floor((i - 1) / 2); }

    leftChild(i) { return (2 * i + 1); }

    rightChild(i) { return (2 * i + 2); }

    insert(element) {
        this.heap.push(element);
        this.heapifyUp(this.heap.length - 1);
    }

    heapifyUp(i) {
        if (i > 0 && this.heap[this.parent(i)] < this.heap[i]) {
            let p = this.parent(i);
            this.swap(p, i);
            this.heapifyUp(p);
        }
    }

    extractMax() {
        if (this.heap.length === 1) {
            return this.heap.pop();
        }
        let max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown(0);
        return max;
    }

    heapifyDown(i) {
        let left = this.leftChild(i), right = this.rightChild(i);
        if (left < this.heap.length && this.heap[left] > this.heap[i]) {
            let largest = left;
        } else {
            largest = i;
        }
        if (right < this.heap.length && this.heap[right] > this.heap[largest]) {
            largest = right;
        }
        if (largest !== i) {
            this.swap(i, largest);
            this.heapifyDown(largest);
        }
    }

    swap(i, j) {
        let temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }

    max() {
        return this.heap.length > 0 ? this.heap[0] : undefined;
    }
}

This code reads the inputs in a line, splits them into an array and processes them. The `MaxHeap` class is used to implement the max heap data structure, and the `insert`, `extractMax`, `heapifyUp`, and `heapifyDown` methods handle the insertion, extraction, and maintaining the heap property. The `max` method is used to get the maximum element in the heap, and the `swap` method is used to swap elements in the heap.