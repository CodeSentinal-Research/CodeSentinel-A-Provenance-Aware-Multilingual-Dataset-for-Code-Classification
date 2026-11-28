const fs = require('fs');
function hanoi(n, src, dst, aux) {
    if (n === 1) {
        console.log(`Move disk 1 from ${src} to ${dst}`);
        return;
    }
    hanoi(n - 1, src, aux, dst);
    console.log(`Move disk ${n} from ${src} to ${dst}`);
    hanoi(n - 1, aux, dst, src);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        hanoi(n, 'A', 'C', 'B');
        console.log((2n ** BigInt(n) - 1n).toString());
    }
}
main();