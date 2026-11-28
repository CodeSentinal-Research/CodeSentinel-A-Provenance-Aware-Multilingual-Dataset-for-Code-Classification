function minWindow(s, t) {
    if (!s || !t) return "";
    const need = {};
    for (const c of t) need[c] = (need[c] || 0) + 1;

    let missing = t.length;
    let i = 0, start = 0, minLen = Infinity;

    for (let j = 0; j < s.length; j++) {
        const c = s[j];
        if (need[c] > 0) missing--;
        need[c] = (need[c] || 0) - 1;

        if (missing === 0) {
            while (i < j && need[s[i]] < 0) {
                need[s[i]]++;
                i++;
            }
            if (j - i + 1 < minLen) {
                start = i;
                minLen = j - i + 1;
            }
            need[s[i]]++;
            missing++;
            i++;
        }
    }
    return minLen === Infinity ? "" : s.substring(start, start + minLen);
}

module.exports = { minWindow };