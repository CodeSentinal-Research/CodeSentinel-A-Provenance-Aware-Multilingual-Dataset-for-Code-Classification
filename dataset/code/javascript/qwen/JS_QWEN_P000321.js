const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const words = input.trim().split(/\s+/);
    const rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
    let res = [];
    for(let w of words) {
        let lower = w.toLowerCase();
        let row = rows.find(r => r.includes(lower[0]));
        if(row && [...lower].every(c => row.includes(c))) res.push(w);
    }
    console.log(res.join(" "));
    rl.close();
});
