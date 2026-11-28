const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        const dict = new Set(lines.slice(2, 2+n));
        
        let res = [];
        function dfs(start, curr) {
            if (start === s.length) {
                res.push(curr.trim());
                return;
            }
            for (let end = start + 1; end <= s.length; end++) {
                let word = s.substring(start, end);
                if (dict.has(word)) {
                    dfs(end, curr + " " + word);
                }
            }
        }
        dfs(0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
