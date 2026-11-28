const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const courses = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { courses.push({c: tokens[idx], inst: tokens[idx+1]}); idx += 2; }
        const target = tokens[idx];
        courses.filter(x => x.inst === target).forEach(x => console.log(x.c));
    }
}
main();