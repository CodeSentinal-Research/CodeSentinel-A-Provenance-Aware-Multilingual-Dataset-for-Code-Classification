function checkInclusion(s1, s2) {
    const n1 = s1.length, n2 = s2.length;
    if (n1 > n2) return false;

    const c1 = new Array(26).fill(0);
    const c2 = new Array(26).fill(0);
    const a = 'a'.charCodeAt(0);

    for (let i = 0; i < n1; i++) c1[s1.charCodeAt(i) - a]++;

    for (let i = 0; i < n2; i++) {
        c2[s2.charCodeAt(i) - a]++;
        if (i >= n1) c2[s2.charCodeAt(i - n1) - a]--;
        if (c1.every((val, idx) => val === c2[idx])) return true;
    }
    return false;
}

module.exports = { checkInclusion };