const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', (line) => {
    if (arr.length === 0) {
        arr[0] = Number(line);
    } else {
        arr.push(Number(line));
    }

    if (arr.length === 3) {
        const [N, ...heap] = arr;
        const [i] = arr.slice(N);

        const heapify = (arr, n, i) => {
            let largest = i;
            let left = 2 * i + 1;
            let right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest])
                largest = left;

            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr, i, largest);
                heapify(arr, n, largest);
            }
        };

        const swap = (arr, i, j) => {
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        };

        heapify(arr, N, i);
        console.log(arr.slice(1).join(' '));
    }
});