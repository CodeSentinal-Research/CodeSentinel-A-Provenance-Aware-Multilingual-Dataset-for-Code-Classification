// Helper function to evaluate ispalindrome for problem constraints.
function isPalindrome(x) {
    if (x < 0) return false;
    const s = x.toString();
    return s === s.split('').reverse().join('');
}

module.exports = { isPalindrome };