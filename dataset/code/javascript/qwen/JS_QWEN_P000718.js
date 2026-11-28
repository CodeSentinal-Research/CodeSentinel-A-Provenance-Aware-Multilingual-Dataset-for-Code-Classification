const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = ["0", "1"];
    for (let i = 2; i <= n; i++) {
        let temp = [];
        for (let j = res.length - 1; j >= 0; j--) temp.push("0" + res[j]);
        for (let j = 0; j < res.length; j++) temp.push("1" + res[j]);
        res = temp;
    }
    console.log(res.join("\n"));
    rl.close();
});
