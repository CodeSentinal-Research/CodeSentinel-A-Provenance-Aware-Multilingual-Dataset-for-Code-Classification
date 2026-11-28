const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const m = parseInt(lines[1]);
        let logs = lines.slice(2);
        let res = new Array(n).fill(0);
        let stack = [];
        for(let log of logs) {
            let [id, type, time] = log.split(':');
            id=parseInt(id); time=parseInt(time);
            if(type==='start') {
                if(stack.length) res[stack[stack.length-1]] -= time;
                stack.push(id);
            } else {
                let top = stack.pop();
                res[top] += time + 1;
                if(stack.length) res[stack[stack.length-1]] += time + 1;
            }
        }
        console.log(res.join(" "));
        rl.close();
    }
});
