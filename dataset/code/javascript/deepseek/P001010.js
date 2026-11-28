Here is the JavaScript code for the problem:

let arr = []
let n = parseInt(readline())
readline().split(' ').map(Number).forEach(function(num) {
    arr.push(num)
})

function maxHeapify(arr, n, i) {
    let largest = i
    let left = 2 * i + 1
    let right = 2 * i + 2

    if (left < n && arr[left] > arr[largest]) {
        largest = left
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right
    }

    if (largest != i) {
        swap(arr, i, largest)
        maxHeapify(arr, n, largest)
    }
}

function swap(arr, i, j) {
    let temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
}

function buildMaxHeap(arr, n) {
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i)
    }
}

function printArray(arr, n) {
    for (let i = 0; i < n; i++) {
        console.log(arr[i] + " ")
    }
}

buildMaxHeap(arr, n)
printArray(arr, n)
In the above code, we first read the number of elements and the elements themselves. Then we use the `maxHeapify` function to build a Max Heap from the given array. The `maxHeapify` function is used to maintain the heap property. The `buildMaxHeap` function is used to build the Max Heap. Finally, the `printArray` function is used to print the elements of the Max Heap.