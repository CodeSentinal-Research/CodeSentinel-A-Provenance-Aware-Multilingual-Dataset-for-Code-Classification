const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let a=0, l=0, consL=0;
    for(let c of s) {
        if(c==='A') { a++; l=0; }
        else if(c==='L') { l++; if(l>=3) { console.log("No"); rl.close(); return; } }
        else l=0;
    }
    console.log(a<2 ? "Yes" : "No");
    rl.close();
});
