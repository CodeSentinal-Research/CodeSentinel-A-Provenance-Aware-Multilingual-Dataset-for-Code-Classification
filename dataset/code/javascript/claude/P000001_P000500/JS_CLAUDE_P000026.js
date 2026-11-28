function isPalindrome(n) {
    if (n < 0) return false;
    const s = String(n);
    return s === s.split('').reverse().join('');
}

module.exports = { isPalindrome };
