const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let l=0, r=s.length-1;
    while(l<r) {
        if(s[l]!==s[r]) {
            let s1 = s.substring(l+1, r+1);
            let s2 = s.substring(l, r);
            if(s1===s1.split('').reverse().join('') || s2===s2.split('').reverse().join('')) {
                console.log("Yes"); rl.close(); return;
            }
            console.log("No"); rl.close(); return;
        }
        l++; r--;
    }
    console.log("Yes");
    rl.close();
});
