const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        let text = [];
        let cursor = 0;
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'addText') {
                const s = tokens[idx+1];
                text.splice(cursor, 0, ...s.split(''));
                cursor += s.length;
                idx += 2;
            } else if (cmd === 'deleteText') {
                const k = parseInt(tokens[idx+1], 10);
                const delCnt = Math.min(k, cursor);
                text.splice(cursor - delCnt, delCnt);
                cursor -= delCnt;
                console.log(delCnt);
                idx += 2;
            } else if (cmd === 'cursorLeft') {
                const k = parseInt(tokens[idx+1], 10);
                cursor = Math.max(0, cursor - k);
                const l = Math.max(0, cursor - 10);
                console.log(text.slice(l, cursor).join(''));
                idx += 2;
            } else if (cmd === 'cursorRight') {
                const k = parseInt(tokens[idx+1], 10);
                cursor = Math.min(text.length, cursor + k);
                const l = Math.max(0, cursor - 10);
                console.log(text.slice(l, cursor).join(''));
                idx += 2;
            }
        }
    }
}
main();