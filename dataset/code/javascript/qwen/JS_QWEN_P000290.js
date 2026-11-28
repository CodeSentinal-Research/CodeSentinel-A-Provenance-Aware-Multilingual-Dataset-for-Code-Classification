const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const text = lines[0], pattern = lines[1];
        let pCount = {}, tCount = {};
        for(let c of pattern) pCount[c]=(pCount[c]||0)+1;
        let res = [], match=0;
        for(let i=0; i<text.length; i++) {
            tCount[text[i]]=(tCount[text[i]]||0)+1;
            if(tCount[text[i]]===pCount[text[i]]) match++;
            if(i>=pattern.length) {
                if(tCount[text[i-pattern.length]]===pCount[text[i-pattern.length]]) match--;
                tCount[text[i-pattern.length]]--;
                if(tCount[text[i-pattern.length]]===0) delete tCount[text[i-pattern.length]];
            }
            if(match===Object.keys(pCount).length) res.push(i-pattern.length+1);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
