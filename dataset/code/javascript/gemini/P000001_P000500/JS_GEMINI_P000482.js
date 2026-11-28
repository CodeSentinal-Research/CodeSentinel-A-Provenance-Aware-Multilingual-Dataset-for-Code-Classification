const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums1 = tokens.slice(1, 1 + n).map(Number);
        const m = parseInt(tokens[1 + n], 10);
        const nums2 = tokens.slice(2 + n, 2 + n + m).map(Number);
        const nxt = new Map();
        const st = [];
        for (const x of nums2) {
            while (st.length > 0 && st[st.length - 1] < x) {
                nxt.set(st.pop(), x);
            }
            st.push(x);
        }
        while (st.length > 0) nxt.set(st.pop(), -1);
        console.log(nums1.map(x => nxt.get(x)).join(' '));
    }
}
main();