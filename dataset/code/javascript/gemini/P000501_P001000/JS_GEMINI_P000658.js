const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const wins = new Map();
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'newWindow') {
                const id = parseInt(tokens[idx+1], 10);
                const home = tokens[idx+2];
                wins.set(id, {hist: [home], cur: 0});
                idx += 3;
            } else if (cmd === 'visit') {
                const id = parseInt(tokens[idx+1], 10);
                const url = tokens[idx+2];
                const w = wins.get(id);
                w.hist = w.hist.slice(0, w.cur + 1);
                w.hist.push(url);
                w.cur++;
                idx += 3;
            } else if (cmd === 'back') {
                const id = parseInt(tokens[idx+1], 10);
                const steps = parseInt(tokens[idx+2], 10);
                const w = wins.get(id);
                w.cur = Math.max(0, w.cur - steps);
                console.log(w.hist[w.cur]);
                idx += 3;
            } else if (cmd === 'forward') {
                const id = parseInt(tokens[idx+1], 10);
                const steps = parseInt(tokens[idx+2], 10);
                const w = wins.get(id);
                w.cur = Math.min(w.hist.length - 1, w.cur + steps);
                console.log(w.hist[w.cur]);
                idx += 3;
            } else if (cmd === 'currentPage') {
                const id = parseInt(tokens[idx+1], 10);
                console.log(wins.get(id).hist[wins.get(id).cur]);
                idx += 2;
            } else if (cmd === 'closeWindow') {
                const id = parseInt(tokens[idx+1], 10);
                wins.delete(id);
                idx += 2;
            }
        }
    }
}
main();