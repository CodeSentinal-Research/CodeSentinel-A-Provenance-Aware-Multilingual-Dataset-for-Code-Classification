const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const word = lines[0], abbr = lines[1];
        let i=0, j=0;
        while(i<word.length && j<abbr.length) {
            if(abbr[j]>='0' && abbr[j]<='9') {
                if(abbr[j]==='0') { console.log("No"); rl.close(); return; }
                let num=0;
                while(j<abbr.length && abbr[j]>='0' && abbr[j]<='9') num = num*10 + parseInt(abbr[j++]);
                i+=num;
            } else {
                if(word[i]!==abbr[j]) { console.log("No"); rl.close(); return; }
                i++; j++;
            }
        }
        console.log(i===word.length && j===abbr.length ? "Yes" : "No");
        rl.close();
    }
});
