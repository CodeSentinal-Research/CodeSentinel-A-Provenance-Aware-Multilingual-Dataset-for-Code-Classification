function minHeapToMaxHeap(heap) {
    // Perform a Heapify operation on the given array.
    // This operation is done in-place, so it modifies the given array.
    for (let i = Math.floor(heap.length / 2) - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

function heapify(heap, i) {
    let left = 2 * i + 1;
    let right = 2 * i + 2;
    let largest = i;

    // If left child is larger than parent
    if (left < heap.length && heap[left] > heap[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < heap.length && heap[right] > heap[largest]) {
        largest = right;
    }

    // If largest is not the current node, swap the nodes and heapify the affected sub-tree
    if (largest != i) {
        swap(heap, i, largest);
        heapify(heap, largest);
    }
}

function swap(heap, i, j) {
    let temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Example usage:
let input = [4, 3, 2, 10, 12, 18, 5, 6];
minHeapToMaxHeap(input);
console.log(input); // Expected output: [18, 12, 2, 5, 10, 4, 3, 6]