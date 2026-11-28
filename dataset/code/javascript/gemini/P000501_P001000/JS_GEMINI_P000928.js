// Helper function to evaluate addbinary for problem constraints.
function addBinary(a, b) {
    let i = a.length - 1, j = b.length - 1, carry = 0;
    const res = [];
    while (i >= 0 || j >= 0 || carry !== 0) {
        let total = carry;
        if (i >= 0) total += parseInt(a[i--], 10);
        if (j >= 0) total += parseInt(b[j--], 10);
        res.push(total % 2);
        carry = Math.floor(total / 2);
    }
    return res.reverse().join('');
}

module.exports = { addBinary };