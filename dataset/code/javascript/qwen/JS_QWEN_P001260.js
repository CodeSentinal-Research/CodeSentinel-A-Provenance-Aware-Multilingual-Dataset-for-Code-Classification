const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, c] = lines[0].split(/\s+/).map(Number);
        let res = "";
        let pq = [[a,'a'], [b,'b'], [c,'c']].sort((x,y)=>y[0]-x[0]);
        
        while(pq[0][0]>0) {
            let [cnt, char] = pq.shift();
            if(res.length>=2 && res[res.length-1]===char && res[res.length-2]===char) {
                if(pq.length===0) break;
                let [cnt2, char2] = pq.shift();
                res+=char2; cnt2--;
                pq.unshift([cnt2, char2]);
                pq.sort((x,y)=>y[0]-x[0]);
                pq.unshift([cnt, char]);
                pq.sort((x,y)=>y[0]-x[0]);
            } else {
                res+=char; cnt--;
                pq.unshift([cnt, char]);
                pq.sort((x,y)=>y[0]-x[0]);
            }
        }
        console.log(res);
        rl.close();
    }
});
