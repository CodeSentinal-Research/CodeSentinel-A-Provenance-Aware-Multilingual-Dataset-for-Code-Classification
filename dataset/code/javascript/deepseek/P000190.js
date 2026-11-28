Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N: ', (N) => {
    rl.question('Enter N+1 integers separated by space: ', (inputs) => {
        const nums = inputs.split(' ').map(Number);
        const set = new Set();
        let duplicate = -1;

        for (let num of nums) {
            if (set.has(num)) {
                duplicate = num;
                break;
            }
            set.add(num);
        }

        console.log('The duplicate number is: ' + duplicate);

        rl.close();
    });
});

This code uses the readline module to read input from the user. First, it reads the number N from the user. Then, it reads N+1 integers, converts them to numbers, and adds them to a Set (which automatically removes duplicates). It then checks each number in the Set, and if it is found to be in the Set (indicating a duplicate), it stores this number in the `duplicate` variable and stops checking further. Finally, it outputs the duplicate number.