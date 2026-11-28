const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = 0;
rl.question('Enter N: ', (N) => {
    const arr = [];
    rl.setPrompt('Enter numbers: ');
    rl.prompt();
    rl.on('line', (line) => {
        if (line.trim() === '') {
            rl.close();
            partitionPairs(arr);
        } else {
            arr.push(parseInt(line));
        }
    });
});

function partitionPairs(arr) {
    if (arr.length % 2 !== 0) {
        console.log('NO');
    } else {
        const frequency = {};
        arr.forEach(element => {
            frequency[element] = (frequency[element] || 0) + 1;
        });

        const maxFreq = Math.max(...Object.values(frequency));

        if (maxFreq % 2 !== 0) {
            console.log('NO');
        } else {
            console.log('YES');
        }
    }
}