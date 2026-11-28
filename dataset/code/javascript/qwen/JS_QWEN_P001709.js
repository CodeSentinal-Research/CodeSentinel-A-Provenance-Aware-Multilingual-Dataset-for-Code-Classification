const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let moves = [];
    function hanoi(n, src, aux, dest) {
        if (n === 1) {
            moves.push(`Move disk 1 from ${src} to ${dest}`);
            return;
        }
        hanoi(n - 1, src, dest, aux);
        moves.push(`Move disk ${n} from ${src} to ${dest}`);
        hanoi(n - 1, aux, src, dest);
    }
    hanoi(n, 'A', 'B', 'C');
    console.log(moves.join("\n"));
    console.log(Math.pow(2, n) - 1);
    rl.close();
});
