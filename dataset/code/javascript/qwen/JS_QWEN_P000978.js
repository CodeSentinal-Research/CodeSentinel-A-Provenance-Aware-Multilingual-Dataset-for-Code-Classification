const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [x1, y1, x2, y2, x3, y3] = line.split(/\s+/).map(Number);
        let d1 = (x1-x2)**2 + (y1-y2)**2;
        let d2 = (x2-x3)**2 + (y2-y3)**2;
        let d3 = (x1-x3)**2 + (y1-y3)**2;
        if(d1===d2 && d2===d3) console.log("Equilateral");
        else if(d1===d2 || d2===d3 || d1===d3) console.log("Isosceles");
        else console.log("Scalene");
        rl.close();
    }
});
