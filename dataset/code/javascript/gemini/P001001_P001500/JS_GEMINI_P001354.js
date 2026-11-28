// Helper function to evaluate splitintofibonacci for problem constraints.
function splitIntoFibonacci(num) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx) {
        if (idx === num.length && res.length >= 3) return true;
        for (let i = idx + 1; i <= num.length; i++) {
            if (num[idx] === '0' && i > idx + 1) break;
            const val = Number(num.slice(idx, i));
            if (val > 2147483647) break;

            const size = res.length;
            if (size >= 2) {
                const sum = res[size - 1] + res[size - 2];
                if (val < sum) continue;
                else if (val > sum) break;
            }

            res.push(val);
            if (backtrack(i)) return true;
            res.pop();
        }
        return false;
    }

    backtrack(0);
    return res;
}

module.exports = { splitIntoFibonacci };