function kSmallest(arr, k) {
    let maxHeap = new MaxHeap();

    for (let i = 0; i < arr.length; i++) {
        maxHeap.insert(arr[i]);
        if (maxHeap.size() > k) {
            maxHeap.poll();
        }
    }

    while (maxHeap.size() > k) {
        maxHeap.poll();
    }

    return maxHeap.root;
}

class MaxHeap {
    constructor() {
        this.heap = [];
    }

    get parent() {
        return (i) => this.heap[this.getParent(i)];
    }

    get leftChild() {
        return (i) => this.heap[this.getLeftChild(i)];
    }

    get rightChild() {
        return (i) => this.heap[this.getRightChild(i)];
    }

    getSibling(i) {
        let parent = this.getParent(i);
        return (this.getLeftChild(parent) === i) ? this.getRightChild(parent) : this.getLeftChild(parent);
    }

    getParent(i) {
        return Math.floor((i - 1) / 2);
    }

    getLeftChild(i) {
        return 2 * i + 1;
    }

    getRightChild(i) {
        return 2 * i + 2;
    }

    insert(data) {
        let node = {data, isMaxHeap: false};
        this.heap.push(node);
        this.siftUp(this.heap.length - 1);
        return node;
    }

    siftUp(i) {
        if (i <= 0) {
            return;
        }
        let parent = this.getParent(i);
        if (this.heap[i].data > this.heap[parent].data) {
            this.swap(i, parent);
            this.siftUp(parent);
        }
    }

    poll() {
        if (this.heap.length === 1) {
            return this.heap.pop();
        }
        let root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.siftDown(0);
        return root;
    }

    siftDown(i) {
        let left = this.getLeftChild(i);
        let right = this.getRightChild(i);
        let maxIndex = i;
        if (left < this.heap.length && this.heap[left].data > this.heap[maxIndex].data) {
            maxIndex = left;
        }
        if (right < this.heap.length && this.heap[right].data > this.heap[maxIndex].data) {
            maxIndex = right;
        }
        if (maxIndex !== i) {
            this.swap(i, maxIndex);
            this.siftDown(maxIndex);
        }
    }

    swap(i, j) {
        let temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }
}