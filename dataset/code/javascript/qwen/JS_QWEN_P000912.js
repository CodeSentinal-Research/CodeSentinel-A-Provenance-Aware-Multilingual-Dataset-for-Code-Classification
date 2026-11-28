const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const k = parseInt(input.trim());
    let row = [1];
    for(let i=1; i<=k; i++) {
        let next = [1];
        for(let j=1; j<row.length; j++) {
            next.push(row[j-1] + row[j]);
        }
        next.push(1);
        row = next;
    }
    console.log(row.join(" "));
    rl.close();
});
