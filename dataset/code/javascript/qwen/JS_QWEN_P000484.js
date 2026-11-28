const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const asteroids = lines[1].split(/\s+/).map(Number);
        let stack = [];
        for(let a of asteroids) {
            let destroyed = false;
            while(stack.length && a<0 && stack[stack.length-1]>0) {
                if(stack[stack.length-1] < -a) { stack.pop(); continue; }
                else if(stack[stack.length-1] === -a) { stack.pop(); }
                destroyed = true;
                break;
            }
            if(!destroyed) stack.push(a);
        }
        console.log(stack.join(" "));
        rl.close();
    }
});
