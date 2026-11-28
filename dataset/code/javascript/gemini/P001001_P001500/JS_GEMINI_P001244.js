// Helper function to evaluate reorganizestring for problem constraints.
function reorganizeString(s) {
    const count = new Array(26).fill(0);
    for (const c of s) count[c.charCodeAt(0) - 97]++;

    const pq = [];
    for (let i = 0; i < 26; i++) {
        if (count[i] > 0) pq.push([String.fromCharCode(97 + i), count[i]]);
    }

    const res = [];
    let prev = null;

    while (pq.length > 0) {
        pq.sort((a, b) => b[1] - a[1]);
        const cur = pq.shift();
        res.push(cur[0]);
        cur[1]--;

        if (prev && prev[1] > 0) pq.push(prev);
        prev = cur;
    }

    return res.length === s.length ? res.join('') : "";
}

module.exports = { reorganizeString };