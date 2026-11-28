const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let cars = [];
        for(let i=1; i<=n; i++) cars.push(lines[i].split(/\s+/).map(Number));
        cars.sort((a,b)=>b[0]-a[0]);
        let stack = [];
        let res = new Array(n).fill(-1);
        for(let i=0; i<n; i++) {
            let [pos, spd] = cars[i];
            let time = -1;
            while(stack.length) {
                let [p2, s2, idx2] = stack[stack.length-1];
                if(spd > s2) {
                    let t = (p2-pos)/(spd-s2);
                    if(time===-1 || t<=time) {
                        time = t;
                        stack.pop();
                    } else break;
                } else break;
            }
            res[i] = time;
            stack.push([pos, spd, i]);
        }
        // Map back to original indices if needed, but problem usually asks for order
        console.log(res.map(x => x===-1 ? -1 : x.toFixed(6)).join(" "));
        rl.close();
    }
});
