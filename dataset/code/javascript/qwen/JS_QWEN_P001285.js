const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [x, y] = lines[0].split(/\s+/).map(Number);
        let steps=0;
        while(y>x) {
            if(y%2===0) y/=2;
            else y++;
            steps++;
        }
        console.log(steps+x-y);
        rl.close();
    }
});
