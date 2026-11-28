const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], t = lines[1];
        let need = {}, missing = t.length;
        for(let c of t) need[c]=(need[c]||0)+1;
        let l=0, r=0, start=0, minLen=Infinity;
        while(r<s.length) {
            if(need[s[r]]>0) missing--;
            need[s[r]]=(need[s[r]]||0)-1;
            r++;
            while(missing===0) {
                if(r-l < minLen) { start=l; minLen=r-l; }
                need[s[l]]=(need[s[l]]||0)+1;
                if(need[s[l]]>0) missing++;
                l++;
            }
        }
        console.log(minLen===Infinity ? "" : s.substring(start, start+minLen));
        rl.close();
    }
});
