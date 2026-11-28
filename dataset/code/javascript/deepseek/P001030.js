Here is the JavaScript code for converting a Max Heap to a Min Heap:

function maxHeapToMinHeap(heap) {
    // First, we will convert the max heap into a min heap
    // by swapping all elements with their children in the heap
    for (let i = Math.floor(heap.length / 2) - 1; i >= 0; i--) {
        let key = i;
        let left = 2 * key + 1;
        let right = 2 * key + 2;
        let smallest = key;

        // If left child is larger than root
        if (left < heap.length && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // If right child is larger than smallest so far
        if (right < heap.length && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // If smallest is not the root
        if (smallest != key) {
            swap(heap, key, smallest);
            // Recursively heapify the affected sub-tree
            maxHeapToMinHeap(heap);
        }
    }
}

function swap(array, key, smallest) {
    let temp = array[key];
    array[key] = array[smallest];
    array[smallest] = temp;
}

function solve() {
    let n = parseInt(readline());
    let arr = readline().split(' ').map(Number);
    // Convert the array into a max heap
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
    maxHeapToMinHeap(arr);
    for (let i = 0; i < n; i++) {
        console.log(arr[i] + ' ');
    }
}

function maxHeapify(arr, n, i) {
    let largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr, i, largest);
        maxHeapify(arr, n, largest);
    }
}

function readline() {
    return process.stdin.readline();
}

solve();

This code reads the input, converts the array into a max heap, and then converts the max heap into a min heap. Note that this code assumes that the array is initially a max heap. If the input array is already a min heap, then it will already be a min heap.