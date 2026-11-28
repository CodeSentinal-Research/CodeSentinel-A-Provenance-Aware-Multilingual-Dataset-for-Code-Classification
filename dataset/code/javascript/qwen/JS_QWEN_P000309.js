const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n1 = lines[0], n2 = lines[1];
        let m = n1.length, n = n2.length;
        let prod = new Array(m+n).fill(0);
        for(let i=m-1; i>=0; i--) {
            for(let j=n-1; j>=0; j--) {
                let mul = parseInt(n1[i]) * parseInt(n2[j]);
                let p1 = i+j, p2 = i+j+1;
                let sum = mul + prod[p2];
                prod[p2] = sum % 10;
                prod[p1] += Math.floor(sum / 10);
            }
        }
        let res = prod.map(String).join('').replace(/^0+/, '');
        console.log(res || "0");
        rl.close();
    }
});
