Here is a simple JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];
rl.question('Enter number of elements and the difference (separated by space): ', (line) => {
    arr = line.split(' ');
    let numOfPairs = 0;
    const n = parseInt(arr[0]);
    const k = parseInt(arr[1]);

    if (n < 1 || n > 200000 || n > k || k < 0 || k > 1000000000) {
        rl.close();
        return;
    }

    const hashSet = new Set();
    for(let i = 0; i < n; i++) {
        if(hashSet.has(k - arr[i])) {
            numOfPairs++;
        }
        hashSet.add(arr[i]);
    }

    console.log(numOfPairs);

    rl.close();
});

This code uses the readline module to read from the standard input. The first line of input is read as a string and split into two numbers. These two numbers are the length of the array and the difference K, respectively. Then, the array of integers is read as a string of space-separated numbers. These numbers are stored in an array.

The code then iterates over the array and for each element, it checks if there is a number in the set that subtracts this element and equals K. If it does, it increments the count of pairs. It adds the current element to the set of seen numbers.

Finally, it prints the number of pairs to the standard output.