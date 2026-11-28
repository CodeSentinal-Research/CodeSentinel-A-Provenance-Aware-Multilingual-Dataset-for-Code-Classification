const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    let map = {')':'(', '}':'{', ']':'['};
    let valid = true;
    for(let c of s) {
        if(c==='('||c==='{'||c==='[') stack.push(c);
        else if(map[c]) {
            if(stack.pop() !== map[c]) { valid=false; break; }
        }
    }
    if(stack.length) valid=false;
    console.log(valid ? "Valid" : "Invalid");
    rl.close();
});
