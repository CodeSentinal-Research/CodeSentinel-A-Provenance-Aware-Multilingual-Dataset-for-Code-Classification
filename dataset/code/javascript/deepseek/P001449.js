const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
    rl.question('Enter elements: ', (arrStr) => {
        let arr = arrStr.split(' ').map(num => parseInt(num));
        let seen = new Set();
        let maxAbs = -Infinity;

        for (let num of arr) {
            seen.add(num);
            let absNum = Math.abs(num);
            if (absNum !== 0 && !seen.has(-absNum)) {
                maxAbs = Math.max(maxAbs, absNum);
            }
        }

        if (maxAbs === -Infinity) {
            console.log(-1);
        } else {
            console.log(maxAbs);
        }

        rl.close();
    });
});