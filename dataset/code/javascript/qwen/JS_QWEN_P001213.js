const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0], s2 = lines[1];
        if(s1.length !== s2.length) { console.log("NO"); rl.close(); return; }
        
        let memo = {};
        function isScramble(a, b) {
            if(a===b) return true;
            let key = a+'|'+b;
            if(memo[key]!==undefined) return memo[key];
            
            let freq = {};
            for(let c of a) freq[c]=(freq[c]||0)+1;
            for(let c of b) freq[c]=(freq[c]||0)-1;
            for(let k in freq) if(freq[k]!==0) { memo[key]=false; return false; }
            
            let n = a.length;
            for(let i=1; i<n; i++) {
                if((isScramble(a.substring(0,i), b.substring(0,i)) && isScramble(a.substring(i), b.substring(i))) ||
                   (isScramble(a.substring(0,i), b.substring(n-i)) && isScramble(a.substring(i), b.substring(0,n-i)))) {
                    memo[key]=true; return true;
                }
            }
            memo[key]=false; return false;
        }
        console.log(isScramble(s1, s2) ? "YES" : "NO");
        rl.close();
    }
});
