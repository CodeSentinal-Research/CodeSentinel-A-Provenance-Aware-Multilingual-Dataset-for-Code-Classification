const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function genGray(curr, len) {
        if (curr.length === len) {
            res.push(curr);
            return;
        }
        genGray(curr + "0", len);
        genGray(curr + "1", len);
    }
    // Standard Gray Code generation
    let codes = ["0", "1"];
    for (let i = 2; i <= n; i++) {
        let temp = [];
        for (let j = 0; j < codes.length; j++) temp.push("0" + codes[j]);
        for (let j = codes.length - 1; j >= 0; j--) temp.push("1" + codes[j]);
        codes = temp;
    }
    console.log(codes.join("\n"));
    rl.close();
});
