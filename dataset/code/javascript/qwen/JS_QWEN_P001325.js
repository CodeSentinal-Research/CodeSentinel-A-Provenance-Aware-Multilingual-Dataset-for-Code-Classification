const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [n, k] = input.split(/\s+/).map(Number);
    let res = [];
    function combine(start, curr) {
        if(curr.length===k) { res.push(curr.slice()); return; }
        for(let i=start; i<=n; i++) {
            curr.push(i);
            combine(i+1, curr);
            curr.pop();
        }
    }
    combine(1, []);
    console.log(res.map(r=>r.join(" ")).join("\n"));
    rl.close();
});
