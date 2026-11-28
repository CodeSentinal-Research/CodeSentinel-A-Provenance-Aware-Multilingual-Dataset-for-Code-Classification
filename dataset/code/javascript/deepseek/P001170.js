let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the size of the grid: ', (N) => {
    let grid = [];
    rl.setPrompt(`Enter ${N} rows for the grid:`);
    for (let i = 0; i < N; i++) {
        rl.prompt();
    }
    rl.close();
});