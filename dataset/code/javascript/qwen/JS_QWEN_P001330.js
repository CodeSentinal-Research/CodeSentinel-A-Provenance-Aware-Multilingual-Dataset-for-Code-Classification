const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function isPal(str) { return str === str.split('').reverse().join(''); }
    function partition(start, curr) {
        if(start===s.length) { res.push(curr.join(" ")); return; }
        for(let end=start+1; end<=s.length; end++) {
            let sub = s.substring(start, end);
            if(isPal(sub)) {
                curr.push(sub);
                partition(end, curr);
                curr.pop();
            }
        }
    }
    partition(0, []);
    console.log(res.join("\n"));
    rl.close();
});
