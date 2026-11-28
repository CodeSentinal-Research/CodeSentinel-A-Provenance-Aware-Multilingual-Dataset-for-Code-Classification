const fs = require('fs');
function countOfAtoms(formula) {
    const st = [{}];
    let i = 0, n = formula.length;
    while (i < n) {
        if (formula[i] === '(') {
            st.push({});
            i++;
        } else if (formula[i] === ')') {
            i++;
            let iStart = i;
            while (i < n && !isNaN(formula[i]) && formula[i] !== ' ') i++;
            let mult = (iStart === i) ? 1 : parseInt(formula.slice(iStart, i), 10);
            let top = st.pop();
            for (const [atom, cnt] of Object.entries(top)) {
                st[st.length - 1][atom] = (st[st.length - 1][atom] || 0) + cnt * mult;
            }
        } else {
            let iStart = i++;
            while (i < n && formula[i] >= 'a' && formula[i] <= 'z') i++;
            let atom = formula.slice(iStart, i);
            iStart = i;
            while (i < n && !isNaN(formula[i]) && formula[i] !== ' ') i++;
            let cnt = (iStart === i) ? 1 : parseInt(formula.slice(iStart, i), 10);
            st[st.length - 1][atom] = (st[st.length - 1][atom] || 0) + cnt;
        }
    }
    const counts = st[0];
    return Object.keys(counts).sort().map(a => a + (counts[a] > 1 ? counts[a] : '')).join('');
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) console.log(countOfAtoms(s));
}
main();