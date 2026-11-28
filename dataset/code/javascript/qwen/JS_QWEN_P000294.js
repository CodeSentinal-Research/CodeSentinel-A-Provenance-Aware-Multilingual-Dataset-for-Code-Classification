const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], numRows = parseInt(lines[1]);
        if(numRows===1) { console.log(s); rl.close(); return; }
        let rows = Array(numRows).fill('');
        let curRow=0, down=false;
        for(let c of s) {
            rows[curRow]+=c;
            if(curRow===0 || curRow===numRows-1) down=!down;
            curRow += down ? 1 : -1;
        }
        console.log(rows.join(''));
        rl.close();
    }
});
