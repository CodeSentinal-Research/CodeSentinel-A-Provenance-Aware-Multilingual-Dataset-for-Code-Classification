const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [k, n] = input.split(/\s+/).map(Number);
    let res = [];
    function backtrack(start, curr, sum) {
        if(curr.length===k && sum===n) { res.push(curr.slice()); return; }
        if(curr.length>k || sum>n) return;
        for(let i=start; i<=9; i++) {
            curr.push(i);
            backtrack(i+1, curr, sum+i);
            curr.pop();
        }
    }
    backtrack(1, [], 0);
    console.log(res.map(r=>r.join(" ")).join("\n"));
    rl.close();
});
