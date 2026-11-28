const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const target = parseInt(input.trim());
    let res = [];
    function roll(curr, sum) {
        if(sum===target) { res.push(curr.join(" ")); return; }
        if(sum>target) return;
        for(let i=1; i<=6; i++) {
            roll([...curr, i], sum+i);
        }
    }
    roll([], 0);
    console.log(res.join("\n"));
    rl.close();
});
