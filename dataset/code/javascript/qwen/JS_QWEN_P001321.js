const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const digits = input.trim();
    const map = ['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz'];
    let res = [];
    function backtrack(i, s) {
        if(i===digits.length) { if(s) res.push(s); return; }
        for(let c of map[parseInt(digits[i])]) backtrack(i+1, s+c);
    }
    backtrack(0,'');
    console.log(res.join("\n"));
    rl.close();
});
