const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const dict = new Set(lines[1].split(/\s+/));
        let res = [];
        function partition(s, curr) {
            if (s.length === 0) {
                res.push(curr.trim());
                return;
            }
            for (let i = 1; i <= s.length; i++) {
                let sub = s.substring(0, i);
                if (dict.has(sub)) {
                    partition(s.substring(i), curr + " " + sub);
                }
            }
        }
        partition(s, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
