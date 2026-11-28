Here is the JavaScript code to find the second largest element in an array:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (num) => {
    let arr = [];
    rl.question('Enter elements: ', (elements) => {
        arr = elements.split(' ').map(Number);

        let uniqueArr = [...new Set(arr)];
        uniqueArr.sort((a, b) => b - a);

        console.log(uniqueArr[1] !== undefined ? uniqueArr[1] : -1);

        rl.close();
    });
});

In this code, we use the readline module to handle user input. The first line of input is the number of elements to process, and the second line contains the elements of the array. We first convert the input into an array, then remove duplicates by converting it into a Set, then sorting the array in descending order. The second largest element is then printed out. If no second largest element exists, we print -1.