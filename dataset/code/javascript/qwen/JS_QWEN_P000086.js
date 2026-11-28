const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const u = parseInt(input.trim());
    let bill = 0;
    if(u <= 100) bill = u * 10;
    else if(u <= 200) bill = 1000 + (u-100)*15;
    else if(u <= 300) bill = 2500 + (u-200)*20;
    else bill = 4500 + (u-300)*25;
    console.log(bill.toFixed(2));
    rl.close();
});
