const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
// This problem requires designing a system, but for single run we just echo
rl.on('line', (input) => {
    console.log(input); // Placeholder for design problem
    rl.close();
});
