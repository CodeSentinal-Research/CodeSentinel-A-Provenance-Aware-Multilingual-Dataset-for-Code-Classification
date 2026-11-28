Here is the JavaScript code for finding the kth element of two sorted arrays:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr1 = [];
let arr2 = [];

rl.question('Enter the size of the first array (M): ', (M) => {
    rl.question('Enter elements of the first array: ', (element) => {
        arr1 = element.split(' ').map(Number);

        rl.question('Enter the size of the second array (N): ', (N) => {
            rl.question('Enter elements of the second array: ', (element) => {
                arr2 = element.split(' ').map(Number);

                let k = parseInt(rl.question('Enter the kth element you want to find (1 ≤ K ≤ M+N): '));

                let result = findKthElement(arr1, arr2, k);
                console.log('The kth element is: ', result);

                rl.close();
            });
        });
    });
});

function findKthElement(arr1, arr2, k) {
    let i = 0, j = 0;
    let merged = [];

    while(i < arr1.length && j < arr2.length) {
        if(arr1[i] < arr2[j]) {
            merged.push(arr1[i]);
            i++;
        } else {
            merged.push(arr2[j]);
            j++;
        }
    }

    while(i < arr1.length) {
        merged.push(arr1[i]);
        i++;
    }

    while(j < arr2.length) {
        merged.push(arr2[j]);
        j++;
    }

    return merged[k-1];
}

This code uses the readline module to read inputs from the console. The `rl.question()` function is used to read a line from the console and the `console.log()` function is used to print the output. The `findKthElement()` function merges the two sorted arrays and finds the kth element.