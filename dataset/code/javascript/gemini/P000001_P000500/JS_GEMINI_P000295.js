function myAtoi(s) {
    s = s.trim();
    if (!s) return 0;

    let sign = 1, i = 0;
    if (s[0] === '+' || s[0] === '-') {
        if (s[0] === '-') sign = -1;
        i++;
    }

    let res = 0;
    const INT_MAX = 2147483647;
    const INT_MIN = -2147483648;

    while (i < s.length && /\d/.test(s[i])) {
        res = res * 10 + Number(s[i]);
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;
        i++;
    }
    return sign * res;
}

module.exports = { myAtoi };