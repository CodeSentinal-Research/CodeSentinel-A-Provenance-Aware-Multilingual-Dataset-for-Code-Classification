Here is the JavaScript code for the Gold Mine Problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter R and C (separated by space): ', (R) => {
    let row = R.split(' ');
    R = Math.abs(parseInt(row[0]));
    C = Math.abs(parseInt(row[1]));

    let gold = new Array(R).fill(0).map(() => new Array(C).fill(0));

    for (let i = 0; i < R; i++) {
        rl.question(`Enter ${C} numbers separated by space (for row ${i + 1}): `, (line) => {
            let rowData = line.split(' ').map(Number);
            for (let j = 0; j < C; j++) {
                gold[i][j] = rowData[j];
            }
            rl.pause();
        });
    }

    let maxGold = 0;

    function maxGoldHelper(x, y, gold) {
        if (x < 0 || y < 0 || x >= R || y >= C || gold[x][y] <= 0) {
            return;
        }

        gold[x][y] = 0;
        maxGold = Math.max(maxGold, gold[x][y] + maxGoldHelper(x + 1, y, gold.slice()) +
            maxGoldHelper(x - 1, y, gold.slice()) +
            maxGoldHelper(x, y + 1, gold.slice()) +
            maxGoldHelper(x, y - 1, gold.slice()));

        gold[x][y] = gold[x][y] || 0;
    }

    maxGoldHelper(0, 0, Array.from(gold, () => 0));

    console.log(maxGold);
    rl.close();
});

This program reads the input R and C, and then reads R lines each containing C integers representing the gold values. Then it calculates the maximum gold that can be collected.