const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let contentMap = {};
        for (let i = 1; i <= n; i++) {
            let parts = lines[i].split(' ');
            let path = parts[0];
            for (let j = 1; j < parts.length; j++) {
                let content = parts[j].split('(')[1].slice(0, -1);
                if (!contentMap[content]) contentMap[content] = [];
                contentMap[content].push(path + '/' + parts[j].split('(')[0]);
            }
        }
        
        for (let k in contentMap) {
            if (contentMap[k].length > 1) console.log(contentMap[k].join(" "));
        }
        rl.close();
    }
});
