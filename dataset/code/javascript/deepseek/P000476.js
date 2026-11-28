Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (num) => {
    let arr = [];
    rl.question('Enter the elements: ', (input) => {
        arr = input.split(' ').map(Number);
        console.log('The unique element is: ' + findUniqueElement(arr));
        rl.close();
    });
});

function findUniqueElement(arr) {
    let xor = 0;
    for(let i = 0; i < arr.length; i++) {
        xor ^= arr[i];
    }
    return xor;
}

In this code, we are using the XOR bitwise operator to find the unique element in the sorted array. The XOR of all elements in the array will give us the unique element. This is because, if two elements are the same, their XOR will be zero. Therefore, we XOR all elements in the array, and the result will be the unique element.

You can test this code by running it in your local environment and providing input as per the problem statement.