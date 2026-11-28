Here is the JavaScript code for the problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Please enter the number of police and thieves: ', (N) => {
    rl.question('Please enter the string of length N: ', (input) => {
        let police = 0;
        let maxThieves = 0;
        let thieves = 0;

        for (let i = 0; i < N; i++) {
            if (input[i] === 'P') {
                if (thieves > 0) {
                    if (i - lastThief > K) {
                        maxThieves++;
                        thieves = 0;
                    } else {
                        thieves = 0;
                    }
                }
                police++;
                lastPolice = i;
            } else if (input[i] === 'T') {
                thieves++;
                lastThief = i;
            }
        }

        if (thieves > 0) {
            if (N - lastThief > K) {
                maxThieves++;
            }
        }

        console.log(maxThieves);

        rl.close();
    });
});

This code uses the readline module to get user input. It counts the number of police and thieves, and keeps track of the last seen police and thief. If a thief is detected within the range of K, it increments the count of maxThieves. If a police is detected, it resets the count of thieves. The maximum number of thieves found is then printed.