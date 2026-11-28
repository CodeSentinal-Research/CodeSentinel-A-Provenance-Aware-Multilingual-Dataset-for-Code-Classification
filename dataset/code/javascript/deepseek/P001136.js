Here is the JavaScript code that solves the problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter a number: ', function(N) {
    N = parseInt(N);
    if (N >= 0 && N <= 37) {
        console.log(Tribonacci(N));
    } else {
        console.log('Please enter a number between 0 and 37');
    }
    rl.close();
});

function Tribonacci(N) {
    let T = [0, 1, 1];

    if (N < 3) {
        return T[N];
    }

    for (let i = 3; i <= N; i++) {
        T.push(T[i - 1] + T[i - 2] + T[i - 3]);
    }

    return T[N];
}

You can run this code in your local environment. If you run it in a online JavaScript compiler, make sure to import the `readline` module using `require('readline')`. You will be asked for a number input. If the number is between 0 and 37, you will be given the result of the Tribonacci function. If the number is outside the range, you will be prompted to enter a valid number.