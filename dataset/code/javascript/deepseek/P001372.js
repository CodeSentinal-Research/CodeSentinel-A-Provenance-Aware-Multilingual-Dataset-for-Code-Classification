Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (num) => {
    rl.question('Enter the elements: ', (inputs) => {
        let arr = inputs.split(' ').map(Number);
        let seen = new Set();
        for (let num of arr) {
            if (seen.has(num)) {
                console.log('YES');
                rl.close();
                return;
            }
            seen.add(num);
        }
        console.log('NO');
        rl.close();
    });
});

This script will read the number of elements and then the elements themselves from the user. It will then use a Set to keep track of the numbers it has seen so far. If it encounters a number that it has already seen, it will print 'YES' and stop. If it doesn't encounter any repeated numbers in the array, it will print 'NO'.

Note: This is a basic implementation and may not be efficient for large inputs. For larger inputs, you might need a more complex solution, such as using a hashtable or a sorting algorithm, which can be more efficient.