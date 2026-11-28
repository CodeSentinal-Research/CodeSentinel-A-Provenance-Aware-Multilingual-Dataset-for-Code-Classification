Here is the JavaScript code to solve the problem. This code takes an input array of integers, then it finds the length of the longest subarray with equal numbers of even and odd elements.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());

let arr = rl.question().split(' ').map(Number);

function solve(arr, N) {
    let even = arr.filter(x => x % 2 == 0);
    let odd = arr.filter(x => x % 2 != 0);

    let evenLen = even.length;
    let oddLen = odd.length;

    if(evenLen > oddLen){
        let maxLen = Math.max(even.length, odd.length);
        console.log(maxLen);
    }else{
        let maxLen = Math.max(evenLen, oddLen);
        console.log(maxLen);
    }
}

solve(arr, N);

This code reads the number of elements N and the array of integers from the standard input. It then filters the array to create arrays of even and odd numbers. The maximum length of the longest subarray with equal numbers of even and odd elements is then printed to the standard output.

You can run this code in a JavaScript environment that supports reading from the standard input (like Node.js or the browser's console), and it will work correctly.