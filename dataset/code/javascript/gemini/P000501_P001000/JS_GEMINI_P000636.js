const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        let tabs = [];
        let curIdx = 0;
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'open') {
                tabs.push(tokens[idx+1]);
                curIdx = tabs.length - 1;
                idx += 2;
            } else if (cmd === 'close') {
                const i = parseInt(tokens[idx+1], 10);
                tabs.splice(i, 1);
                if (curIdx >= tabs.length) curIdx = Math.max(0, tabs.length - 1);
                idx += 2;
            } else if (cmd === 'switch') {
                curIdx = parseInt(tokens[idx+1], 10);
                idx += 2;
            } else if (cmd === 'moveLeft') {
                const i = parseInt(tokens[idx+1], 10);
                if (i > 0) {
                    [tabs[i], tabs[i-1]] = [tabs[i-1], tabs[i]];
                    if (curIdx === i) curIdx = i - 1;
                    else if (curIdx === i - 1) curIdx = i;
                }
                idx += 2;
            } else if (cmd === 'moveRight') {
                const i = parseInt(tokens[idx+1], 10);
                if (i < tabs.length - 1) {
                    [tabs[i], tabs[i+1]] = [tabs[i+1], tabs[i]];
                    if (curIdx === i) curIdx = i + 1;
                    else if (curIdx === i + 1) curIdx = i;
                }
                idx += 2;
            } else if (cmd === 'current') {
                console.log(tabs.length > 0 ? tabs[curIdx] : '');
                idx += 1;
            }
        }
    }
}
main();