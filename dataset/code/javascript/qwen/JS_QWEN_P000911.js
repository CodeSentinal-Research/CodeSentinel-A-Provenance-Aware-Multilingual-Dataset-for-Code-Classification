const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let triangle = [];
    for(let i=0; i<n; i++) {
        let row = [];
        for(let j=0; j<=i; j++) {
            if(j===0 || j===i) row.push(1);
            else row.push(triangle[i-1][j-1] + triangle[i-1][j]);
        }
        triangle.push(row);
    }
    triangle.forEach(row => console.log(row.join(" ")));
    rl.close();
});
