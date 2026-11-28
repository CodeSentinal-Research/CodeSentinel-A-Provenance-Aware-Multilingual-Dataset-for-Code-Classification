function mergeMaxHeaps(arr1, arr2) {
    let heap1 = new MaxHeap(arr1);
    let heap2 = new MaxHeap(arr2);
    let mergedHeap = new MaxHeap();

    while(heap1.length || heap2.length) {
        if(heap1.peek() !== undefined) {
            mergedHeap.insert(heap1.extractMax());
        }
        if(heap2.peek() !== undefined) {
            mergedHeap.insert(heap2.extractMax());
        }
    }

    return mergedHeap;
}

class MaxHeap {
    constructor() {
        this.array = [0];
    }

    get parent() {
        return (i) => this.array[Math.floor((i + 1) / 2) - 1];
    }

    getChild() {
        return (i) => this.array[2 * i + 1];
    }

    swap(i, j) {
        [this.array[i], this.array[j]] = [this.array[j], this.array[i]];
    }

    siftUp(i) {
        while (i > 0 && this.array[this.parent(i)] < this.array[i]) {
            this.swap(this.parent(i), i);
            i = this.parent(i);
        }
    }

    insert(data) {
        this.array[this.array.length - 1] = data;
        this.siftUp(this.array.length - 1);
        return this.array;
    }

    siftDown(i) {
        while (this.getChild(i) < this.array.length - 1 &&
            this.array[this.getChild(i)] > this.array[this.getChild(i + 1)]) {
            this.swap(this.getChild(i), this.getChild(i + 1));
            i = this.getChild(i);
        }
    }

    peek() {
        return this.array[0];
    }

    extractMax() {
        const max = this.array[0];
        this.array[0] = this.array[this.array.length - 1];
        this.array.pop();
        this.siftDown(0);
        return max;
    }

    size() {
        return this.array.length - 1;
    }
}
This code first defines a `MaxHeap` class that represents a max heap data structure. The `MaxHeap` class has methods for sifting up, down, swapping, and inserting data. It also has methods for peeking at the max element, extracting the max element, and getting the parent and child of an element. The `mergeMaxHeaps` function takes two max heaps as input, merges them into a single max heap, and returns the merged heap.