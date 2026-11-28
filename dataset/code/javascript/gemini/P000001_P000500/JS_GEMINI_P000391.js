const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const students = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            students.push({name: tokens[idx], gpa: parseFloat(tokens[idx + 1])});
            idx += 2;
        }
        const threshold = parseFloat(tokens[idx]);
        students.filter(s => s.gpa >= threshold).forEach(s => console.log(s.name));
    }
}

main();