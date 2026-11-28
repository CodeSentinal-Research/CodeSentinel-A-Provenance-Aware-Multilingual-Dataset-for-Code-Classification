Here is the JavaScript solution for the given problem:

function solve() {
    var fs = require('fs');
    process.stdin.resume();
    process.stdin.setEncoding('ascii');
    var inputStream = process.stdin;
    var outputStream = process.stdout;
    var input = '';
    var currentLength = 0;
    inputStream.on('data', function(data) {
        input += data;
        currentLength = input.length;
    });
    inputStream.on('end', function() {
        input = input.split('\n');
        var N = parseInt(input[0]);
        var K = parseInt(input[1]);
        var arr = input[2].split(' ').map(Number);
        var minHeap = new MinHeap(arr.slice(0, K + 1));
        arr.slice(K + 1).forEach(function(num) {
            if (num < minHeap.peek()) {
                minHeap.poll();
                minHeap.insert(num);
            }
        });
        var result = minHeap.getArray();
        outputStream.write(result.join(' ') + '\n');
        process.exit();
    });
}

var MinHeap = (function() {
    function MinHeap(arr) {
        this.heap = [];
        if (arr) this.buildHeap(arr);
    }
    MinHeap.prototype.parent = function(i) {
        return Math.floor((i - 1) / 2);
    };
    MinHeap.prototype.leftChild = function(i) {
        return (2 * i + 1);
    };
    MinHeap.prototype.rightChild = function(i) {
        return (2 * i + 2);
    };
    MinHeap.prototype.buildHeap = function(arr) {
        this.heap = arr;
        for (var i = this.parent(this.heap.length - 1); i >= 0; i--) {
            this.heapify(i);
        }
    };
    MinHeap.prototype.heapify = function(i) {
        var left = this.leftChild(i);
        var right = this.rightChild(i);
        var smallest = i;
        if (left < this.heap.length && this.heap[left] < this.heap[smallest]) smallest = left;
        if (right < this.heap.length && this.heap[right] < this.heap[smallest]) smallest = right;
        if (smallest != i) {
            var temp = this.heap[i];
            this.heap[i] = this.heap[smallest];
            this.heap[smallest] = temp;
            this.heapify(smallest);
        }
    };
    MinHeap.prototype.insert = function(val) {
        this.heap.push(val);
        var i = this.heap.length - 1;
        while (i > 0 && this.heap[this.parent(i)] > this.heap[i]) {
            var temp = this.heap[i];
            this.heap[i] = this.heap[this.parent(i)];
            this.heap[this.parent(i)] = temp;
            i = this.parent(i);
        }
    };
    MinHeap.prototype.poll = function() {
        var ret = this.heap[0];
        this.heap[0] = this.heap[this.heap.length - 1];
        this.heap.pop();
        this.heapify(0);
        return ret;
    };
    MinHeap.prototype.peek = function() {
        return this.heap[0];
    };
    MinHeap.prototype.getArray = function() {
        return this.heap;
    };
    return MinHeap;
})();

solve();

This code uses a MinHeap to keep the smallest elements in the array in a sorted order. It builds the heap first and then processes the rest of the array. The smallest element is always at the root of the heap. Every time a new element is added, it is inserted into the heap and then heapified. The smallest element is then removed from the heap. This process is repeated for the rest of the array.