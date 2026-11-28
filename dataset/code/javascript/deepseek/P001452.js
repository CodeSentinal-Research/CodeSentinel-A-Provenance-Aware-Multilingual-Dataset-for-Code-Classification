Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [N, Q] = rl.question('').split(' ').map(num => parseInt(num, 10));
let arr = rl.question('').split(' ').map(num => parseInt(num, 10));

let distinctSet = new Set(arr);

rl.setPrompt(`${N} ${Q}\n`);

rl.question('', (query) => {
    let [index, newValue] = query.split(' ').map(num => parseInt(num, 10));
    arr[index] = newValue;
    distinctSet.delete(arr[index]);
    distinctSet.add(arr[index]);
    console.log(distinctSet.size);
});

rl.close();

In this code, we first read the size of the array and the number of queries from the standard input. Then, we read the array from the standard input. We use a Set to store the distinct elements in the array. After each query, we replace the value at the specified index with the new value and update the Set. The size of the Set at the end of each query is printed to the standard output.