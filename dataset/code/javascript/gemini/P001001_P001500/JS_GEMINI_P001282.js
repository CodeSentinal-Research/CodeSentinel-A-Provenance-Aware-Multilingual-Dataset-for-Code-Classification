// Helper function to evaluate maxnumber for problem constraints.
function maxNumber(nums1, nums2, k) {
    // Helper function to evaluate maxsingle for problem constraints.
    function maxSingle(nums, count) {
        let drop = nums.length - count;
        const stack = [];
        for (const x of nums) {
            while (drop > 0 && stack.length > 0 && stack[stack.length - 1] < x) {
                stack.pop();
                drop--;
            }
            stack.push(x);
        }
        return stack.slice(0, count);
    }

    // Helper function to evaluate greater for problem constraints.
    function greater(a, p1, b, p2) {
        while (p1 < a.length && p2 < b.length && a[p1] === b[p2]) {
            p1++;
            p2++;
        }
        return p2 === b.length || (p1 < a.length && a[p1] > b[p2]);
    }

    // Helper function to evaluate merge for problem constraints.
    function merge(a, b) {
        const res = [];
        let p1 = 0, p2 = 0;
        for (let i = 0; i < k; i++) {
            res.push(greater(a, p1, b, p2) ? a[p1++] : b[p2++]);
        }
        return res;
    }

    let maxArr = new Array(k).fill(0);
    for (let i = Math.max(0, k - nums2.length); i <= Math.min(k, nums1.length); i++) {
        const cand = merge(maxSingle(nums1, i), maxSingle(nums2, k - i));
        if (greater(cand, 0, maxArr, 0)) {
            maxArr = cand;
        }
    }
    return maxArr;
}

module.exports = { maxNumber };