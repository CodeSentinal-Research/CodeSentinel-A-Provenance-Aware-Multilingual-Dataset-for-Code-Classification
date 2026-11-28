Here is a simple solution to the problem using JavaScript's PriorityQueue and an array:

function mergeKArrays(arrays) {
    let queue = new PriorityQueue((a, b) => a[0] - b[0]);

    for (let i = 0; i < arrays.length; i++) {
        queue.enqueue(arrays[i]);
    }

    let merged = [];

    while (!queue.isEmpty()) {
        let smallest = queue.dequeue();
        merged.push(smallest[1]);
        if (smallest[2]) {
            queue.enqueue(smallest[2]);
        }
    }

    return merged;
}

// PriorityQueue Node
class Node {
    constructor(val, index) {
        this.val = val;
        this.index = index;
    }
}

// PriorityQueue
class PriorityQueue {
    constructor(comparator) {
        this.heap = [];
        this.comparator = comparator;
    }

    // Adds an element
    enqueue(value) {
        let node = new Node(value, this.size());
        this.heap.push(node);
        this.siftUp(node);
    }

    // Removes and returns the smallest element
    dequeue() {
        const removed = this.heap[0];
        const end = this.heap.pop();

        if (this.size() > 0) {
            this.heap[0] = end;
            this.siftDown(this.heap[0]);
        }

        return removed.val;
    }

    // Returns the smallest element
    peek() {
        return this.heap[0].val;
    }

    // Returns the size
    size() {
        return this.heap.length;
    }

    // Returns true if the queue is empty
    isEmpty() {
        return this.size() === 0;
    }

    siftUp(node) {
        let parent = Math.floor((node.index - 1) / 2);

        if (this.comparator(node.val, this.heap[parent].val) < 0) {
            let tmp = this.heap[parent];
            this.heap[parent] = node;
            node.index = parent;
            this.siftUp(tmp);
        }
    }

    siftDown(node) {
        let childIndex = node.index * 2 + 1;

        if (childIndex < this.size() && this.comparator(this.heap[childIndex].val, this.heap[this.getMinChildIndex(node.index)].val) < 0) {
            let tmp = this.heap[childIndex];
            this.heap[childIndex] = this.heap[this.getMinChildIndex(node.index)];
            this.heap[this.getMinChildIndex(node.index)].index = childIndex;
            this.heap[childIndex].index = node.index;
            this.siftDown(tmp);
        }
    }

    getMinChildIndex(parentIndex) {
        let childIndex1 = parentIndex * 2 + 1;
        let childIndex2 = parentIndex * 2 + 2;
        return (childIndex2 < this.size() && this.comparator(this.heap[childIndex2].val, this.heap[childIndex1].val) < 0) ? childIndex2 : childIndex1;
    }
}

In this code, the `mergeKArrays` function creates a PriorityQueue and enqueues all arrays. It then pops the smallest element from the queue, pushes it to the merged array, and then enqueues the next smallest element from the queue. This process continues until the queue is empty. The merged array is returned at the end.

Please note that the `enqueue` method in the `PriorityQueue` class takes an array and enqueues it into the queue. If the array has a second element, it also enqueues the second element into the queue.