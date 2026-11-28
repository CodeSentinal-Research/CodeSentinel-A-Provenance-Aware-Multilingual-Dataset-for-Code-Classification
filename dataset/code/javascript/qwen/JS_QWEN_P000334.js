const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const source = lines[0], target = lines[1];
        let count = 0, i = 0;
        while(i < target.length) {
            let j = 0, found = false;
            for(let k=0; k<source.length; k++) {
                if(source[k] === target[i]) { i++; found = true; }
            }
            if(!found) { console.log(-1); rl.close(); return; }
            count++;
        }
        console.log(count);
        rl.close();
    }
});
