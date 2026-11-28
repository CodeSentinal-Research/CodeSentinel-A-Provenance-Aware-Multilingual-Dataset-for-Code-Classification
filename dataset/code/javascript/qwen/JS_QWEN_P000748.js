const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const target = parseInt(input.trim());
    let res = [];
    function diceRolls(target, curr) {
        if (target === 0) {
            res.push(curr.join(" "));
            return;
        }
        for (let i = 1; i <= 6; i++) {
            if (target - i >= 0) diceRolls(target - i, [...curr, i]);
        }
    }
    diceRolls(target, []);
    console.log(res.join("\n"));
    rl.close();
});
