// Helper function to evaluate maxlength for problem constraints.
function maxLength(arr) {
    // dp table storing optimal subproblem solutions
    const dp = [0];
    let maxLen = 0;

    for (const s of arr) {
        let mask = 0, dup = false;
        for (const c of s) {
            const bit = 1 << (c.charCodeAt(0) - 97);
            if ((mask & bit) > 0) {
                dup = true;
                break;
            }
            mask |= bit;
        }
        if (dup) continue;

        const size = dp.length;
        for (let i = 0; i < size; i++) {
            // Update dynamic programming state transition
            const prev = dp[i];
            if ((prev & mask) === 0) {
                const next = prev | mask;
                dp.push(next);
                let bits = 0, temp = next;
                while (temp > 0) {
                    bits += temp & 1;
                    temp >>= 1;
                }
                if (bits > maxLen) maxLen = bits;
            }
        }
    }
    return maxLen;
}

module.exports = { maxLength };