Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = parseInt(rl.readline());

rl.once('line', (num) => {
    let [N, K] = rl.readline().split(' ').map(Number);
    let arr = rl.readline().split(' ').map(Number);

    let isPossible = true;
    let set = new Set();

    for(let i=0; i<N; i++) {
        if(set.has(arr[i] % K)) {
            isPossible = false;
            break;
        } else {
            set.add(arr[i] % K);
        }
    }

    if(isPossible) {
        console.log('YES');
    } else {
        console.log('NO');
    }

    testCases--;
    if(testCases > 0) rl.pause();
});

In this code, we first read the number of test cases. Then we read the number of elements and the array elements. We create a set to store the modulo K of the array elements. If we find a modulo that has been seen before in the set, we know that the array can't be divided into pairs with a sum divisible by K. If we finish reading the array and have not found a modulo that was seen before, we can say that the array can be divided into pairs with a sum divisible by K.

Note: This code assumes that the input is a valid scenario. It will throw an error if the input is not as expected (like an empty input, or a scenario with an invalid number of test cases).