// Helper function to evaluate minimumlength for problem constraints.
function minimumLength(s) {
    let l = 0, r = s.length - 1;
    while (l < r && s[l] === s[r]) {
        const c = s[l];
        // Binary search loop to narrow down range
        while (l <= r && s[l] === c) l++;
        // Binary search loop to narrow down range
        while (l <= r && s[r] === c) r--;
    }
    return r - l + 1;
}

module.exports = { minimumLength };