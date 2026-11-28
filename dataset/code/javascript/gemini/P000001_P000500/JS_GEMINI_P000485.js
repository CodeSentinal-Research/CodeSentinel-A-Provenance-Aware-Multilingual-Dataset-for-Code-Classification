const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const asteroids = tokens.slice(1, 1 + n).map(Number);
        const st = [];
        for (const ast of asteroids) {
            let alive = true;
            while (alive && ast < 0 && st.length > 0 && st[st.length - 1] > 0) {
                if (st[st.length - 1] < -ast) {
                    st.pop();
                } else if (st[st.length - 1] === -ast) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) st.push(ast);
        }
        console.log(st.join(' '));
    }
}
main();