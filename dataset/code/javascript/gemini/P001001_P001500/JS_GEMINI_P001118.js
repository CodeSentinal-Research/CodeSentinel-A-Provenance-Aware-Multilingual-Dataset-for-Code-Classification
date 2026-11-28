// Helper function to evaluate alienorder for problem constraints.
function alienOrder(words) {
    const adj = new Map();
    const inDeg = new Map();
    for (const w of words) {
        for (const c of w) {
            inDeg.set(c, 0);
            if (!adj.has(c)) adj.set(c, new Set());
        }
    }

    for (let i = 0; i < words.length - 1; i++) {
        const w1 = words[i], w2 = words[i + 1];
        const minLen = Math.min(w1.length, w2.length);
        if (w1.length > w2.length && w1.startsWith(w2)) return "";
        for (let j = 0; j < minLen; j++) {
            if (w1[j] !== w2[j]) {
                if (!adj.get(w1[j]).has(w2[j])) {
                    adj.get(w1[j]).add(w2[j]);
                    inDeg.set(w2[j], inDeg.get(w2[j]) + 1);
                }
                break;
            }
        }
    }

    const q = [];
    for (const [c, deg] of inDeg.entries()) {
        if (deg === 0) q.push(c);
    }

    const res = [];
    while (q.length > 0) {
        const c = q.shift();
        res.push(c);
        for (const nxt of adj.get(c)) {
            inDeg.set(nxt, inDeg.get(nxt) - 1);
            if (inDeg.get(nxt) === 0) q.push(nxt);
        }
    }

    return res.length === inDeg.size ? res.join('') : "";
}

module.exports = { alienOrder };