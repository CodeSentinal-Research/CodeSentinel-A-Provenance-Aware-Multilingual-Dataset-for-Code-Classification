Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let numOfStones = Number(rl.question());
let stones = rl.question().split(' ').map(Number);

rl.close();

let sumOfStones = stones.reduce((acc, cur) => acc + cur, 0);
let firstPlayerStones = sumOfStones - stones[0];

if (firstPlayerStones > stones[1] + stones[2]) {
    console.log('Alice');
} else if (firstPlayerStones < stones[1] + stones[2]) {
    console.log('Bob');
} else {
    console.log('Tie');
}

This code reads the number of stones and the values of the stones from the standard input. It then calculates the sum of the stones and checks if Alice's stones are greater than the sum of Bob's and the third player's stones. If Alice's stones are greater, then Alice wins. If Bob's stones are greater, then Bob wins. If both players' stones are equal, then it is a tie.