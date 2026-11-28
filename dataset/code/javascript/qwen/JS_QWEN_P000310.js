const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const a = lines[0], b = lines[1];
        let i=a.length-1, j=b.length-1, carry=0, res="";
        while(i>=0 || j>=0 || carry) {
            let sum = carry;
            if(i>=0) sum += parseInt(a[i--]);
            if(j>=0) sum += parseInt(b[j--]);
            carry = Math.floor(sum/2);
            res = (sum%2) + res;
        }
        console.log(res);
        rl.close();
    }
});
