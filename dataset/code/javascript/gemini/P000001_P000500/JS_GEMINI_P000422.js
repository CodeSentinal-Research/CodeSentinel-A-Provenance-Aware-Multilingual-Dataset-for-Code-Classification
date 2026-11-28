const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const studs = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { studs.push({name: tokens[idx], gpa: parseFloat(tokens[idx+1]), inc: parseFloat(tokens[idx+2])}); idx += 3; }
        const minGpa = parseFloat(tokens[idx]), maxInc = parseFloat(tokens[idx+1]);
        studs.filter(s => s.gpa >= minGpa && s.inc <= maxInc).forEach(s => console.log(s.name));
    }
}
main();