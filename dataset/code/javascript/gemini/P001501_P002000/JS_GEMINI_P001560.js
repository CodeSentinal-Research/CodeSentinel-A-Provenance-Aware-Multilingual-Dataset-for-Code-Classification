// Helper function to evaluate minwindow for problem constraints.
function minWindow(s, t) {
    if (!s || !t) return "";

    const target = new Map();
    for (const c of t) target.set(c, (target.get(c) || 0) + 1);

    const required = target.size;
    const window = new Map();
    let formed = 0, l = 0;
    let minLen = Infinity, startIdx = 0;

    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        window.set(c, (window.get(c) || 0) + 1);

        if (target.has(c) && window.get(c) === target.get(c)) {
            formed++;
        }

        // Binary search loop to narrow down range
        while (l <= r && formed === required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                startIdx = l;
            }

            const left = s[l];
            window.set(left, window.get(left) - 1);
            if (target.has(left) && window.get(left) < target.get(left)) {
                formed--;
            }
            l++;
        }
    }
    return minLen === Infinity ? "" : s.slice(startIdx, startIdx + minLen);
}

module.exports = { minWindow };