const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let half = s.length / 2;
    let v = ['a','e','i','o','u'];
    let c1 = 0, c2 = 0;
    for(let i=0; i<half; i++) if(v.includes(s[i].toLowerCase())) c1++;
    for(let i=half; i<s.length; i++) if(v.includes(s[i].toLowerCase())) c2++;
    console.log(c1 === c2 ? "Yes" : "No");
    rl.close();
});
