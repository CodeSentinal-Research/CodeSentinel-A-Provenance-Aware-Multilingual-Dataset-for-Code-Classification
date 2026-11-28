const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = new Array(26).fill(0);
    let q = [];
    let res = "";
    for(let c of s) {
        let idx = c.charCodeAt(0)-97;
        count[idx]++;
        if(count[idx]===1) q.push(idx);
        while(q.length && count[q[0]]>1) q.shift();
        res += q.length ? String.fromCharCode(q[0]+97) : '#';
    }
    console.log(res);
    rl.close();
});
