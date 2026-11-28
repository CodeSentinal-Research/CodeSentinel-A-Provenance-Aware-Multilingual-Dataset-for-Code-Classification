const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the size of the array: ', (n) => {
    rl.question('Enter the elements of the array (space separated): ', (arrStr) => {
        const nums = arrStr.split(' ').map(num => parseInt(num));

        const prefixSum = new Array(n + 1).fill(0);
        nums.forEach((num, index) => prefixSum[index + 1] = prefixSum[index] + (num % 2));

        for (let i = 0; i < parseInt(q); i++) {
            rl.question('Enter range ' + (i + 1) + ' (space separated): ', (rangeStr) => {
                const [L, R] = rangeStr.split(' ').map(num => parseInt(num) - 1);
                const count = prefixSum[R] - (L ? prefixSum[L - 1] : 0);
                console.log('Count of even numbers in range ' + (i + 1) + ': ' + count);
            });
       
        }

        rl.close();
    });

});