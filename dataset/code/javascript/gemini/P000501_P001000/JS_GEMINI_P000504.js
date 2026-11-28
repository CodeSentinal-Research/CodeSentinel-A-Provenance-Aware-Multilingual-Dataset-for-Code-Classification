const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), m = parseInt(tokens[1], 10);
        const logs = tokens.slice(2, 2 + m);
        const res = new Array(n).fill(0);
        const st = [];
        let prevTime = 0;
        for (const log of logs) {
            const [sFid, typ, sTime] = log.split(':');
            const fid = parseInt(sFid, 10), time = parseInt(sTime, 10);
            if (typ === 'start') {
                if (st.length > 0) res[st[st.length - 1]] += time - prevTime;
                st.push(fid);
                prevTime = time;
            } else {
                res[st.pop()] += time - prevTime + 1;
                prevTime = time + 1;
            }
        }
        console.log(res.join(' '));
    }
}
main();