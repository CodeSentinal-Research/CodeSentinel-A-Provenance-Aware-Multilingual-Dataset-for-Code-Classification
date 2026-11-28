Here is the JavaScript code to build a Min Heap from an array of integers.

class MinHeap {
  constructor() {
    this.array = [];
  }

  parent(i) {
    return Math.floor((i - 1) / 2);
  }

  leftChild(i) {
    return 2 * i + 1;
  }

  rightChild(i) {
    return 2 * i + 2;
  }

  swap(i, j) {
    let temp = this.array[i];
    this.array[i] = this.array[j];
    this.array[j] = temp;
  }

  heapifyUp(i) {
    if (i > 0 && this.array[i] < this.array[this.parent(i)]) {
      this.swap(i, this.parent(i));
      this.heapifyUp(this.parent(i));
    }
  }

  heapifyDown(i) {
    if (this.leftChild(i) < this.array.length && this.array[i] > this.array[this.leftChild(i)]) {
      this.swap(i, this.leftChild(i));
      this.heapifyDown(this.leftChild(i));
    }
    if (this.rightChild(i) < this.array.length && this.array[i] > this.array[this.rightChild(i)]) {
      this.swap(i, this.rightChild(i));
      this.heapifyDown(this.rightChild(i));
    }
  }

  insert(val) {
    this.array.push(val);
    this.heapifyUp(this.array.length - 1);
  }

  print() {
    console.log(this.array);
  }

  buildHeap(arr) {
    this.array = arr;
    for (let i = Math.floor(this.array.length / 2) - 1; i >= 0; i--) {
      this.heapifyDown(i);
    }
  }
}

// Example usage:
let minHeap = new MinHeap();
minHeap.buildHeap([4, 10, 3, 5, 1]);
minHeap.print(); // Output: [1, 3, 5, 10, 4]

This code defines a MinHeap class with methods to insert values into the heap, print the heap, and build a heap from an array of values.