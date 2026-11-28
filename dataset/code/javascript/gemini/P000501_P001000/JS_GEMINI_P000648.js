const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        let history = [''];
        let cur = 0;
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'type') {
                const s = tokens[idx+1];
                history = history.slice(0, cur + 1);
                history.push(history[history.length - 1] + s);
                cur++;
                idx += 2;
            } else if (cmd === 'undo') {
                if (cur > 0) cur--;
                idx += 1;
            } else if (cmd === 'redo') {
                if (cur + 1 < history.length) cur++;
                idx += 1;
            } else if (cmd === 'print') {
                console.log(history[cur]);
                idx += 1;
            }
        }
    }
}
main();