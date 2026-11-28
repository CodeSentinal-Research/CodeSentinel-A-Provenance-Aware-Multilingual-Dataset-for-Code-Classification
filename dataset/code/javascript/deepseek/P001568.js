const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = parseInt(rl.question().trim());

for(let i=0; i<cases; i++){
    let n = parseInt(rl.question().trim());
    let binary = rl.question().trim().split(' ').map(Number);

    let ones = binary.filter(bit => bit === 1).length;
    let zeros = binary.length - ones;

    if(ones === 0) {
        console.log(zeros);
    } else if(zeros === 0) {
        console.log(ones-1);
    } else {
        console.log(Math.max(ones, zeros) + 1);
    }
}
rl.close();