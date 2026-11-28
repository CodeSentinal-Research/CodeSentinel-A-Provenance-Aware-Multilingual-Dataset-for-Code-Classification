Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.question('Enter the size of the array: ', (size) => {
    rl.question('Enter elements of the array: ', (inputs) => {
        arr = inputs.split(' ').map(Number);
        sortArray(arr);
        console.log(arr.join(' '));
        rl.close();
    });
});

function sortArray(arr) {
    let oneCount = arr.filter(x => x === 1).length;
    let twoCount = arr.filter(x => x === 2).length;

    for(let i = 0; i < oneCount; i++) {
        arr[i] = 1;
    }

    for(let i = oneCount; i < oneCount + twoCount; i++) {
        arr[i] = 2;
    }
}

This code uses readline module to handle user inputs. It first asks for the size of the array, then asks for the elements of the array. After receiving these inputs, it sorts the array using the `sortArray` function. This function counts the number of 1s and 2s in the array, then fills the rest of the array with 1s followed by the rest of the array with 2s.