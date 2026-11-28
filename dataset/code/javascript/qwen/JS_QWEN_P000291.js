const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0], s2 = lines[1];
        if(s1.length > s2.length) { [s1,s2]=[s2,s1]; }
        let count = {};
        for(let c of s1) count[c]=(count[c]||0)+1;
        let l=0, match=0;
        for(let r=0; r<s2.length; r++) {
            if(count[s2[r]]>0) match++;
            count[s2[r]]--;
            if(r-l+1 > s1.length) {
                count[s2[l]]++;
                if(count[s2[l]]>0) match--;
                l++;
            }
            if(match===s1.length) { console.log("Yes"); rl.close(); return; }
        }
        console.log("No");
        rl.close();
    }
});
