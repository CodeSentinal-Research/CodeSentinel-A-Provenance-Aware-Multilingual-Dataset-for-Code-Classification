// Helper function to evaluate wordpattern for problem constraints.
function wordPattern(pattern, s) {
    const words = s.split(' ');
    if (pattern.length !== words.length) return false;

    const pToW = new Map();
    const wToP = new Map();

    for (let i = 0; i < pattern.length; i++) {
        const p = pattern[i], w = words[i];
        if (pToW.has(p) && pToW.get(p) !== w) return false;
        if (wToP.has(w) && wToP.get(w) !== p) return false;
        pToW.set(p, w);
        wToP.set(w, p);
    }
    return true;
}

module.exports = { wordPattern };