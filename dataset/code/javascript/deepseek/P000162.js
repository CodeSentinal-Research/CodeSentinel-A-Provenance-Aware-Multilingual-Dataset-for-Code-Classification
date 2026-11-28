Here is a JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter number of elements: ', (num) => {
    rl.question('Enter target sum: ', (target) => {
        const inputArray = [];
        rl.setRawMode(true);
        rl.question('Enter elements: ', (elements) => {
            elements.split(' ').map(Number).forEach(element => inputArray.push(element));
            let count = 0;
            for (let i = 0; i < inputArray.length; i++) {
                for (let j = i + 1; j < inputArray.length; j++) {
                    if (inputArray[i] + inputArray[j] === parseInt(target)) {
                        count++;
                    }
                }
            }
            console.log('Number of pairs: ', count);
            rl.close();
        });
    });
});

This JavaScript program uses the readline module to read input from the user. It first reads the number of elements, then the target sum. Then it reads the elements and checks if there is a pair whose sum equals the target. The program counts the number of pairs and prints it out.