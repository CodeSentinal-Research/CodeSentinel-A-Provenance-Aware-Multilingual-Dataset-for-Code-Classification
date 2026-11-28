Here is a solution in JavaScript that uses two heaps, a max heap and a min heap to store the numbers. The max heap is used to store the higher half of numbers, and the min heap is used to store the lower half. The median is then the root of the max heap.

class MedianHeap {
    constructor() {
        this.maxHeap = [];
        this.minHeap = [];
    }

    // Add a number to the data structure
    addNum(num) {
        if (this.maxHeap.length === 0 || num < -this.maxHeap[0]) {
            this.maxHeap.push(-num);
        } else {
            this.minHeap.push(num);
        }

        this.rebalance();
    }

    // Get the median
    getMedian() {
        if (this.maxHeap.length === this.minHeap.length) {
            return (-this.maxHeap[0] + this.minHeap[0]) / 2;
        } else if (this.maxHeap.length > this.minHeap.length) {
            return -this.maxHeap[0];
        } else {
            return this.minHeap[0];
        }
    }

    rebalance() {
        if (this.maxHeap.length > this.minHeap.length + 1) {
            let num = this.maxHeap.pop();
            this.minHeap.push(-num);
        } else if (this.maxHeap.length + 1 < this.minHeap.length) {
            let num = this.minHeap.pop();
            this.maxHeap.push(-num);
        }
    }
}

let mh = new MedianHeap();

process.stdin.on('data', (data) => {
    let numbers = data.toString().split(' ').map(n => parseInt(n));

    numbers.forEach((num) => {
        mh.addNum(num);
        console.log(mh.getMedian());
    });

    process.stdin.pause();
});

This code reads a line of numbers from stdin, adds each one to the data structure, and then prints the median. This is done until stdin is exhausted. The process.stdin.pause() is used to prevent the program from exiting after reading the first number because we want to keep processing the input.

You can use this script by piping the input to it, like so: `node script.js < input.txt`. You can also run the script from the command line like this: `node script.js` and then enter numbers when prompted.