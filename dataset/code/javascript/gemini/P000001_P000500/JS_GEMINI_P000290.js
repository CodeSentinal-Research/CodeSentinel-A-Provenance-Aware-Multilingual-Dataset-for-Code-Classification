function findAnagrams(s, p) {
    const res = [];
    const ns = s.length, np = p.length;
    if (ns < np) return res;

    const pCount = new Array(26).fill(0);
    const sCount = new Array(26).fill(0);
    const a = 'a'.charCodeAt(0);

    for (let i = 0; i < np; i++) pCount[p.charCodeAt(i) - a]++;

    for (let i = 0; i < ns; i++) {
        sCount[s.charCodeAt(i) - a]++;
        if (i >= np) sCount[s.charCodeAt(i - np) - a]--;
        if (pCount.every((val, idx) => val === sCount[idx])) {
            res.push(i - np + 1);
        }
    }
    return res;
}

module.exports = { findAnagrams };