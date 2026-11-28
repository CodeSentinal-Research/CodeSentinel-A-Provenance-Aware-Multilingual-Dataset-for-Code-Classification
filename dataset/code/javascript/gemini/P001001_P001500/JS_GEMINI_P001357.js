// Helper function to evaluate isadditivenumber for problem constraints.
function isAdditiveNumber(num) {
    const n = num.length;
    for (let i = 1; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const s1 = num.slice(0, i), s2 = num.slice(i, j);
            if ((s1[0] === '0' && s1.length > 1) || (s2[0] === '0' && s2.length > 1)) {
                continue;
            }

            let n1 = BigInt(s1), n2 = BigInt(s2);
            let k = j;
            while (k < n) {
                const n3 = n1 + n2;
                const s3 = n3.toString();
                if (!num.startsWith(s3, k)) break;
                k += s3.length;
                n1 = n2;
                n2 = n3;
            }
            if (k === n) return true;
        }
    }
    return false;
}

module.exports = { isAdditiveNumber };