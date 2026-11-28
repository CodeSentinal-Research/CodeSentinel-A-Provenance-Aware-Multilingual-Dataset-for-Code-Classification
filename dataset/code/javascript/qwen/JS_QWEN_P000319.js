const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], t = lines[1];
        if(Math.abs(s.length - t.length) > 1) { console.log("No"); rl.close(); return; }
        let i=0, j=0, diff=0;
        while(i<s.length && j<t.length) {
            if(s[i]!==t[j]) {
                diff++;
                if(diff>1) { console.log("No"); rl.close(); return; }
                if(s.length>t.length) i++;
                else if(t.length>s.length) j++;
                else { i++; j++; }
            } else { i++; j++; }
        }
        if(i<s.length || j<t.length) diff++;
        console.log(diff===1 ? "Yes" : "No");
        rl.close();
    }
});
