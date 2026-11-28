Here is a simple JavaScript solution using the Binary Heap data structure. It first constructs a max heap from the input, then prints it.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  let arr = [];
  rl.question('Enter the elements: ', (input) => {
    input = input.split(' ').map(Number);
    arr = buildMaxHeap(input, arr);
    printHeap(arr, 'Max Heap: ');
    rl.close();
  });
});

function buildMaxHeap(input, arr) {
  for (let i = 0; i < input.length; i++) {
    arr.push(input[i]);
  }
  for (let i = Math.floor(arr.length / 2) - 1; i >= 0; i--) {
    heapify(arr, arr.length, i);
  }
  return arr;
}

function heapify(arr, n, i) {
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
    heapify(arr, n, largest);
  }
}

function swap(arr, i, j) {
  let temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

function printHeap(arr, msg) {
  console.log(msg);
  for (let i = 0; i < arr.length; i++) {
    console.log(arr[i] + ' ');
  }
  console.log('------');
}

In this code, we first read the number of elements and the elements from the input. We then create a max heap from the input. Finally, we print the max heap.

Please note that the solution assumes that the input will be valid, i.e., all elements will be non-negative integers, and the number of elements will be within the expected range.