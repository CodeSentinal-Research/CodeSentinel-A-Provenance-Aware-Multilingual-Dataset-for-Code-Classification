const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let collisions = 0;
    let right = 0;
    for(let c of s) {
        if(c==='R') right++;
        else if(c==='L') {
            if(right>0) { collisions += right; right=0; }
            else collisions++;
        } else {
            collisions += right;
            right = 0;
        }
    }
    console.log(collisions);
    rl.close();
});
