const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const words = lines[1].split(/\s+/);
        let bold = new Array(s.length).fill(false);
        for(let w of words) {
            let idx = s.indexOf(w);
            while(idx !== -1) {
                for(let i=idx; i<idx+w.length; i++) bold[i]=true;
                idx = s.indexOf(w, idx+1);
            }
        }
        let res = "", inBold = false;
        for(let i=0; i<s.length; i++) {
            if(bold[i] && !inBold) { res += "<b>"; inBold=true; }
            else if(!bold[i] && inBold) { res += "</b>"; inBold=false; }
            res += s[i];
        }
        if(inBold) res += "</b>";
        console.log(res);
        rl.close();
    }
});
