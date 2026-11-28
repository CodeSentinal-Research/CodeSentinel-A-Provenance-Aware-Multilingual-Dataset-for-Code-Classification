const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const target = parseInt(input.trim());
    let pos=0, speed=1, moves=0;
    while(pos !== target) {
        if((pos < target && speed < 0) || (pos > target && speed > 0)) {
            speed = speed > 0 ? -1 : 1;
            moves++;
        }
        pos += speed;
        speed *= 2;
        moves++;
    }
    console.log(moves);
    rl.close();
});
