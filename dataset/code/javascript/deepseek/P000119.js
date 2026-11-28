Here is the JavaScript code that separates even and odd numbers in an array:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.question('Enter the number of elements: ', (num) => {
    rl.question('Enter each element: ', (element) => {
        arr.push(parseInt(element));
        if (arr.length === num) {
            partitionArray(arr, num);
            rl.close();
        }
    });
});

function partitionArray(arr, num) {
    let i = 0, j = num - 1;
    while (i < j) {
        while (arr[i] % 2 === 0 && i < j) {
            i++;
        }
        while (arr[j] % 2 === 1 && i < j) {
            j--;
        }
        if (i < j) {
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }
    console.log(arr.join(' '));
}

This code uses two pointers, `i` and `j`, to traverse the array from both ends. The `i` pointer starts at the beginning of the array and `j` pointer starts at the end. The two pointers are incremented or decremented on each iteration based on which pointer points to an even or odd number. If both pointers point to an even or odd number, they are swapped. This process is repeated until `i` and `j` cross each other, after which the array is printed.