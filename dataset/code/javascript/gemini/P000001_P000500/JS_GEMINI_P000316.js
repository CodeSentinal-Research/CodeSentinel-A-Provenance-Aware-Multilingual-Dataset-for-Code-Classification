const fs = require('fs');

function isIsomorphic(s, t) {
    if (s.length !== t.length) return false;
    const st = new Map(), ts = new Map();
    for (let i = 0; i < s.length; i++) {
        const c1 = s[i], c2 = t[i];
        if (st.has(c1) && st.get(c1) !== c2) return false;
        if (ts.has(c2) && ts.get(c2) !== c1) return false;
        st.set(c1, c2);
        ts.set(c2, c1);
    }
    return true;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(isIsomorphic(input[0], input[1]) ? "Yes" : "No");
    }
}

main();