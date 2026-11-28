const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter elements: ', (elements) => {
        let nums = elements.split(' ').map(Number);

        let hash = {};
        let repeating = -1;

        for (let num of nums) {
            if (hash[num]) {
                if (hash[num] === 1) {
                    repeating = num;
                    break;
                }
                hash[num]++;
            } else {
                hash[num] = 1;
            }
        }

        console.log(repeating);
        rl.close();
    });
});