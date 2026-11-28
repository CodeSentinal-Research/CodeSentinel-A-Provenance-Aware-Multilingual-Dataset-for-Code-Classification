Here is a JavaScript code that fulfills your request:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
  rl.question('Enter the elements: ', (elements) => {
    let arr = elements.split(' ').map(Number);

    buildMaxHeap(arr);

    console.log('Heap after deletion:', arr);
    rl.close();
  });
});

function buildMaxHeap(arr) {
  for (let i = Math.floor(arr.length / 2) - 1; i >= 0; i--) {
    heapify(arr, arr.length, i);
  }
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

You can test it with the input:

5
1 2 3 4 5