const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements in the array: ', (n) => {
    rl.question('Enter the difference: ', (diff) => {
        const arr = [];
        let str = rl.line();
        arr[0] = +str;
        for (let i = 1; i < n; i++) {
            str = rl.line();
            arr[i] = +str;
        }

        arr.sort((a, b) => a - b);

        for (let i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] === diff) {
                console.log('Yes');
                return;
            }
        }
        console.log('No');
    });
});