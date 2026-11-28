const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let courses = [];
        for(let i=1; i<=n; i++) courses.push(lines[i].split(/\s+/).map(Number));
        
        courses.sort((a,b)=>a[1]-b[1]);
        
        let time=0, heap=[];
        for(let [dur, end] of courses) {
            time+=dur;
            heap.push(dur);
            heap.sort((a,b)=>b-a);
            if(time>end) {
                time-=heap.shift();
            }
        }
        console.log(heap.length);
        rl.close();
    }
});
