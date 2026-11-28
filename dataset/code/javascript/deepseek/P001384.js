const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.question('Enter number of elements: ', (num) => {
    N = Number(num);
    let arr = [];
    rl.question('Enter elements: ', (elements) => {
        arr = elements.split(' ').map(Number);
        findDuplicates(arr, N).forEach(element => console.log(element));
        rl.close();
    });
});

function findDuplicates(arr, N) {
    let duplicates = new Array(N).fill(0);
    let result = [];

    for (let num of arr) {
        duplicates[num - 1]++;
    }

    for (let i = 0; i < N; i++) {
        if (duplicates[i] > 1) {
            result.push(i + 1);
        }
    }
    return result;
}
This JavaScript code uses readline module to read input from the console. The first input is the number of elements in the array and the second line contains the elements of the array. The findDuplicates function is then used to find all the duplicates in the array.