const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], t = lines[1];
        function process(str) {
            let stack = [];
            for(let c of str) {
                if(c==='#') stack.pop();
                else stack.push(c);
            }
            return stack.join('');
        }
        console.log(process(s) === process(t) ? "true" : "false");
        rl.close();
    }
});
