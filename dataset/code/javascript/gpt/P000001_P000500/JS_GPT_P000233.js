// P000233 - Maximum Size Rectangle of All 1s
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
function maxHist(h) {
    const st = [];
    let best = 0;
    const h2 = h.concat([0]);
    for (let i = 0; i < h2.length; i++) {
        while (st.length && h2[st[st.length - 1]] > h2[i]) {
            const k = st.pop();
            const left = st.length ? st[st.length - 1] + 1 : 0;
            best = Math.max(best, h2[k] * (i - left));
        }
        st.push(i);
    }
    return best;
}
const h = Array(c).fill(0);
let ans = 0;
for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) h[j] = a[i][j] === 1 ? h[j] + 1 : 0;
    ans = Math.max(ans, maxHist(h));
}
console.log(ans);
