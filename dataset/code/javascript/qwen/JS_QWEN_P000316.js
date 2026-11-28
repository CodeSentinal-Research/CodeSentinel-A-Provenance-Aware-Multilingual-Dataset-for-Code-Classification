const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], t = lines[1];
        if(s.length !== t.length) { console.log("No"); rl.close(); return; }
        let mapS={}, mapT={};
        for(let i=0; i<s.length; i++) {
            if(mapS[s[i]] && mapS[s[i]] !== t[i]) { console.log("No"); rl.close(); return; }
            if(mapT[t[i]] && mapT[t[i]] !== s[i]) { console.log("No"); rl.close(); return; }
            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        }
        console.log("Yes");
        rl.close();
    }
});
