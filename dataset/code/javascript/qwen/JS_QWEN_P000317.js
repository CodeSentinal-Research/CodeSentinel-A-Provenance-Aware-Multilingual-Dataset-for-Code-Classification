const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const pattern = lines[0];
        const words = lines[1].split(/\s+/);
        if(pattern.length !== words.length) { console.log("No"); rl.close(); return; }
        let mapP={}, mapW={};
        for(let i=0; i<pattern.length; i++) {
            if(mapP[pattern[i]] && mapP[pattern[i]] !== words[i]) { console.log("No"); rl.close(); return; }
            if(mapW[words[i]] && mapW[words[i]] !== pattern[i]) { console.log("No"); rl.close(); return; }
            mapP[pattern[i]] = words[i];
            mapW[words[i]] = pattern[i];
        }
        console.log("Yes");
        rl.close();
    }
});
