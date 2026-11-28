const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function backtrack(s, parts) {
        if(parts.length === 4) {
            if(s === "") res.push(parts.join("."));
            return;
        }
        for(let i=1; i<=3; i++) {
            if(i > s.length) break;
            let sub = s.substring(0, i);
            if((sub.length > 1 && sub[0] === '0') || parseInt(sub) > 255) continue;
            backtrack(s.substring(i), [...parts, sub]);
        }
    }
    backtrack(s, []);
    console.log(res.join("\n"));
    rl.close();
});
