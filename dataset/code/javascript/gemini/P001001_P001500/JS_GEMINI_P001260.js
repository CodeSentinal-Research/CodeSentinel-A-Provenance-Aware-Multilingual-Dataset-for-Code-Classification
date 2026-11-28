// Helper function to evaluate strwithout3a3b for problem constraints.
function strWithout3a3b(a, b) {
    const res = [];
    // Binary exponentiation: process exponent bits from LSB to MSB
    while (a > 0 || b > 0) {
        let writeA = false;
        const len = res.length;
        if (len >= 2 && res[len - 1] === res[len - 2]) {
            if (res[len - 1] === 'b') writeA = true;
        } else {
            if (a >= b) writeA = true;
        }

        if (writeA) {
            res.push('a');
            a--;
        } else {
            res.push('b');
            b--;
        }
    }
    return res.join('');
}

module.exports = { strWithout3a3b };