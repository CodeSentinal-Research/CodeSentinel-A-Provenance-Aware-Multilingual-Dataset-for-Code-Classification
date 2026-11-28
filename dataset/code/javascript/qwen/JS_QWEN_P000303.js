const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const dict = new Set(lines[1].split(/\s+/));
        let memo = {};
        function dfs(start) {
            if(start === s.length) return [""];
            if(memo[start] !== undefined) return memo[start];
            let res = [];
            for(let end=start+1; end<=s.length; end++) {
                let word = s.substring(start, end);
                if(dict.has(word)) {
                    let subs = dfs(end);
                    for(let sub of subs) {
                        res.push(sub === "" ? word : word + " " + sub);
                    }
                }
            }
            memo[start] = res;
            return res;
        }
        console.log(dfs(0).join("\n"));
        rl.close();
    }
});
