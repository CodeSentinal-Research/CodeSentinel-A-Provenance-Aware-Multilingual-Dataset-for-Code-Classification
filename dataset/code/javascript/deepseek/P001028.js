Here is the JavaScript code for the problem. The code is using a binary heap data structure to solve the problem. The code first reads the number of elements and the elements themselves. Then, it reads the index of the element to be deleted. It then deletes the element using sift-down operation and finally prints the updated heap.

let readline = require('readline');
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let heap = [];

rl.on('line', function(line) {
    heap.push(parseInt(line));
});

rl.on('line', function(line) {
    heap.push(parseInt(line));
});

rl.on('line', function(line) {
    let index = parseInt(line);
    siftDown(heap, index);
    console.log(heap.join(" "));
    process.exit();
});

function siftDown(arr, index) {
    let parent = Math.floor((index - 1) / 2);

    if (index <= 0 || arr[parent] < arr[index]) {
        return;
    }

    let temp = arr[parent];
    arr[parent] = arr[index];
    arr[index] = temp;

    siftDown(arr, parent);
}

You can run this script by piping input into it. For example, if you have an array [1, 3, 5, 7, 9] and you want to delete element at index 2 (which is 5 in this case), you would pipe that into the script, like this:

echo "5" | node script.js

This would print the updated heap to the console.