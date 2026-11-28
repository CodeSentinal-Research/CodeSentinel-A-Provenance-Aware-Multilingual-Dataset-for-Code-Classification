const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const ratings = lines[1].split(/\s+/).map(Number);
        
        let candies = new Array(n).fill(1);
        for(let i=1; i<n; i++) if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        for(let i=n-2; i>=0; i--) if(ratings[i]>ratings[i+1]) candies[i]=Math.max(candies[i], candies[i+1]+1);
        
        console.log(candies.reduce((a,b)=>a+b, 0));
        rl.close();
    }
});
