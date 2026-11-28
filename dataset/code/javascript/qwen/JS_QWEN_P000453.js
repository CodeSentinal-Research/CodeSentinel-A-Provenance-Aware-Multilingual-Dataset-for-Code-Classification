const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, mStr] = lines[0].split(/\s+/).map(Number);
        const books = lines[1].split(/\s+/).map(Number);
        const m = parseInt(mStr);
        if(m>n) { console.log(-1); rl.close(); return; }
        let l=Math.max(...books), r=books.reduce((a,b)=>a+b,0);
        while(l<r) {
            let mid = Math.floor((l+r)/2);
            let students=1, curr=0;
            for(let b of books) {
                if(curr+b > mid) { students++; curr=b; }
                else curr+=b;
            }
            if(students>m) l=mid+1;
            else r=mid;
        }
        console.log(l);
        rl.close();
    }
});
