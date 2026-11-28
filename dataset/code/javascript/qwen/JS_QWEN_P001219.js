const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        let wordSet = new Set();
        for(let i=2; i<2+n; i++) wordSet.add(lines[i]);
        
        let memo = {};
        function dfs(start) {
            if(start===s.length) return [""];
            if(memo[start]!==undefined) return memo[start];
            
            let res = [];
            for(let end=start+1; end<=s.length; end++) {
                let word = s.substring(start, end);
                if(wordSet.has(word)) {
                    let subs = dfs(end);
                    for(let sub of subs) {
                        res.push(sub==="" ? word : word + " " + sub);
                    }
                }
            }
            memo[start] = res;
            return res;
        }
        let result = dfs(0);
        if(result.length===0) console.log("");
        else console.log(result.join("\n"));
        rl.close();
    }
});
