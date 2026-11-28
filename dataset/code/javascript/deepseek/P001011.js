Here is the JavaScript code to implement Heap Sort:

function heapify(arr, n, i) {
  let largest = i;
  let left = 2 * i + 1;
  let right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    let swap = arr[i];
    arr[i] = arr[largest];
    arr[largest] = swap;

    heapify(arr, n, largest);
  }
}

function heapSort(arr) {
  let n = arr.length;

  for (let i = Math.floor(n / 2) - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (let i = n - 1; i >= 0; i--) {
    let temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);
  }
}

let arr = [12, 11, 13, 5, 6, 7];
heapSort(arr);
console.log(arr);

In this code, `heapify` is a helper function that ensures the heap property is maintained at the node at index `i`. `heapSort` function sorts the array and calls `heapify` on all parent nodes starting from the last internal node (the one at the halfway point) up to the root node.