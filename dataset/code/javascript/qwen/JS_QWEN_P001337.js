const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        let dict = new Set();
        for(let i=2; i<2+n; i++) dict.add(lines[i]);
        
        let res = [];
        function dfs(start, curr) {
            if(start===s.length) { res.push(curr.trim()); return; }
            for(let end=start+1; end<=s.length; end++) {
                let word = s.substring(start, end);
                if(dict.has(word)) {
                    dfs(end, curr + " " + word);
                }
            }
        }
        dfs(0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
