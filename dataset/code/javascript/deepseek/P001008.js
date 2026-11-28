Here is a simple implementation of the problem in JavaScript:

process.stdin.resume();
process.stdin.on('data', function(data) {
    var N = parseInt(data);
    var arr = process.stdin.read().toString().split(' ').map(Number);
    var value = process.stdin.read().toString().split(' ')[0];
    
    var heap = new Heap(arr, function(a, b) { return a - b });
    heap.insert(value);
    
    console.log(heap.root.join(' '));
});

In this code, a new Heap object is created from the given array and a comparison function is passed which sorts the heap in ascending order. The `insert` method is then used to add the new value to the heap. The heap is printed to the console.

This code assumes that you have a Heap class defined elsewhere in your code. The Heap class is defined as:

function Heap(arr, comparator) {
    this.comparator = comparator;
    this.root = arr;
    this.heapifyUp = function(i) {
        var parent = Math.floor((i - 1) / 2);
        if (i && this.comparator(this.root[i], this.root[parent])) {
            var temp = this.root[i];
            this.root[i] = this.root[parent];
            this.root[parent] = temp;
            this.heapifyUp(parent);
        }
    };
    this.insert = function(value) {
        this.root.push(value);
        this.heapifyUp(this.root.length - 1);
    };
    this.heapifyDown = function(i) {
        var left = (i * 2) + 1;
        var right = (i * 2) + 2;
        var smallest = i;
        if (left < this.root.length && this.comparator(this.root[left], this.root[smallest])) {
            smallest = left;
        }
        if (right < this.root.length && this.comparator(this.root[right], this.root[smallest])) {
            smallest = right;
        }
        if (smallest != i) {
            var temp = this.root[i];
            this.root[i] = this.root[smallest];
            this.root[smallest] = temp;
            this.heapifyDown(smallest);
        }
    };
    this.extractMin = function() {
        var min = this.root[0];
        this.root[0] = this.root[this.root.length - 1];
        this.root.pop();
        this.heapifyDown(0);
        return min;
    };
}

Please replace the `Heap` class definition with your own implementation if it's different.