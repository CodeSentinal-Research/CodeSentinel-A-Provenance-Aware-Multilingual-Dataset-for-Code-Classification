function aggressiveCows(stalls, k) {
    stalls.sort((a, b) => a - b);
    let left = 1, right = stalls[stalls.length - 1] - stalls[0];
    let ans = 1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let cows = 1, last = stalls[0];
        for (let i = 1; i < stalls.length; i++) {
            if (stalls[i] - last >= mid) {
                cows++;
                last = stalls[i];
            }
        }
        if (cows >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

module.exports = { aggressiveCows };