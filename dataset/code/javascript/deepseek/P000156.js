Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = parseInt(rl.question());

rl.close();

for(let i=0; i<cases; i++){
    let input = rl.question().split(' ');
    let arr = input[0].split('').map(Number).reverse();
    let maxConsecutiveZeros = 0;
    let currentConsecutiveZeros = 0;

    for(let j=0; j<arr.length; j++){
        if(arr[j] === 0){
            currentConsecutiveZeros++;
            maxConsecutiveZeros = Math.max(maxConsecutiveZeros, currentConsecutiveZeros);
        } else {
            currentConsecutiveZeros = 0;
        }
    }

    console.log(maxConsecutiveZeros);
}

This JavaScript program reads the number of test cases and for each test case it reads the binary number as input. It then counts the number of consecutive zeros and keeps track of the maximum count so far. After all the test cases are processed, it outputs the maximum count.