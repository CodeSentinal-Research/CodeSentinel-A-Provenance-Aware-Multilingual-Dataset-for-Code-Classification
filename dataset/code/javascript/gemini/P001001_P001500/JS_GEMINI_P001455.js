// Helper function to evaluate longestdupsubstring for problem constraints.
function longestDupSubstring(s) {
    const n = s.length;
    let low = 1, high = n - 1;
    let res = "";

    // Performs search to locate target element within the given collection.
    function search(L) {
        const seen = new Set();
        for (let i = 0; i <= n - L; i++) {
            const sub = s.slice(i, i + L);
            if (seen.has(sub)) return sub;
            seen.add(sub);
        }
        return "";
    }

    // Binary search loop to narrow down range
    while (low <= high) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((low + high) / 2);
        const sub = search(mid);
        if (sub) {
            res = sub;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

module.exports = { longestDupSubstring };