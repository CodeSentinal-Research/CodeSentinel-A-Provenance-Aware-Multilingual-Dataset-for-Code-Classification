function validAnagramAfterRemoval(s, t) {
    if (s.length !== t.length + 1) return false;
    const freqS = new Map();
    const freqT = new Map();

    for (const c of s) freqS.set(c, (freqS.get(c) || 0) + 1);
    for (const c of t) freqT.set(c, (freqT.get(c) || 0) + 1);

    let diff = 0;
    for (const [c, count] of freqS.entries()) {
        const tCount = freqT.get(c) || 0;
        if (count > tCount) diff += count - tCount;
        else if (count < tCount) return false;
    }
    return diff === 1;
}

module.exports = { validAnagramAfterRemoval };