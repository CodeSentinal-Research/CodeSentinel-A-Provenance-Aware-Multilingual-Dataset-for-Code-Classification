Here is the JavaScript code that accomplishes the task:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (num) => {
    let arr = [];
    rl.question('Enter the elements: ', (input) => {
        arr = input.split(' ').map(Number);
        if (isSorted(arr)) {
            console.log('Sorted');
        } else {
            console.log('Not Sorted');
        }
        rl.close();
    });
});

function isSorted(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

This code prompts the user to enter the number of elements and then each element, separated by space, and checks if the array is sorted in ascending order. If the array is sorted, it prints "Sorted"; otherwise, it prints "Not Sorted".