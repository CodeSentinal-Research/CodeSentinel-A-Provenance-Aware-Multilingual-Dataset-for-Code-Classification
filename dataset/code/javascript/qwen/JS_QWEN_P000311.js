const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n1 = lines[0], n2 = lines[1];
        let i=n1.length-1, j=n2.length-1, carry=0, res="";
        while(i>=0 || j>=0 || carry) {
            let sum = carry;
            if(i>=0) sum += parseInt(n1[i--]);
            if(j>=0) sum += parseInt(n2[j--]);
            carry = Math.floor(sum/10);
            res = (sum%10) + res;
        }
        console.log(res);
        rl.close();
    }
});
