Here is the JavaScript code that handles the problem:

function divide(dividend, divisor) {
    if (divisor === 0) {
        return Infinity;
    }

    const sign = (dividend < 0) ^  (divisor < 0) ? -1 : 1;
    dividend = Math.abs(dividend);
    divisor = Math.abs(divisor);

    let quotient = 0;
    let temp = 0;

    for (let i = 31; i >= 0; --i) {
        if ((temp + (divisor << i)) <= dividend) {
            temp += divisor << i;
            quotient |= 1 << i;
        }
    }

    return sign * quotient;
}
This function works by subtracting the divisor repeatedly until the dividend is less than the divisor. The number of times the divisor is subtracted is the quotient. This solution works in O(logN) time, where N is the dividend.