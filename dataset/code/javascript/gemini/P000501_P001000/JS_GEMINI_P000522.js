const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const home = tokens[0];
        const q = parseInt(tokens[1], 10);
        let idx = 2;
        let history = [home];
        let curr = 0;
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'visit') {
                const url = tokens[idx+1];
                history = history.slice(0, curr + 1);
                history.push(url);
                curr++;
                idx += 2;
            } else if (cmd === 'back') {
                const steps = parseInt(tokens[idx+1], 10);
                curr = Math.max(0, curr - steps);
                console.log(history[curr]);
                idx += 2;
            } else if (cmd === 'forward') {
                const steps = parseInt(tokens[idx+1], 10);
                curr = Math.min(history.length - 1, curr + steps);
                console.log(history[curr]);
                idx += 2;
            }
        }
    }
}
main();