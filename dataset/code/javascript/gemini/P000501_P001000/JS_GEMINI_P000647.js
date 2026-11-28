const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        let playlist = [];
        let cur = 0;
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'addSong') {
                playlist.push(tokens[idx+1]);
                idx += 2;
            } else if (cmd === 'removeSong') {
                const title = tokens[idx+1];
                const i = playlist.indexOf(title);
                if (i !== -1) {
                    playlist.splice(i, 1);
                    if (cur >= playlist.length) cur = Math.max(0, playlist.length - 1);
                }
                idx += 2;
            } else if (cmd === 'playNext') {
                if (playlist.length > 0) {
                    cur = (cur + 1) % playlist.length;
                    console.log(playlist[cur]);
                }
                idx += 1;
            } else if (cmd === 'playPrevious') {
                if (playlist.length > 0) {
                    cur = (cur - 1 + playlist.length) % playlist.length;
                    console.log(playlist[cur]);
                }
                idx += 1;
            } else if (cmd === 'moveSong') {
                const title = tokens[idx+1];
                const pos = parseInt(tokens[idx+2], 10);
                const i = playlist.indexOf(title);
                if (i !== -1) {
                    playlist.splice(i, 1);
                    playlist.splice(pos, 0, title);
                }
                idx += 3;
            } else if (cmd === 'currentSong') {
                console.log(playlist.length > 0 ? playlist[cur] : '');
                idx += 1;
            }
        }
    }
}
main();