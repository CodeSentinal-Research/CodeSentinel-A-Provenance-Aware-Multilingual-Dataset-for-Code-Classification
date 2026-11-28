// Solves 'First Bad Version' by applying optimal Binary Search logic.
function solution(isBadVersion) {
    return function(n) {
        let left = 1, right = n;
        let ans = n;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor(left + (right - left) / 2);
            if (isBadVersion(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    };
}

module.exports = { solution };