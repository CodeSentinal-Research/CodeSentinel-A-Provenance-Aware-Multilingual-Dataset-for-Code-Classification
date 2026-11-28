// Helper function to evaluate ispalindrome for problem constraints.
function isPalindrome(s) {
    const clean = s.toLowerCase().replace(/[^a-z0-9]/g, '');
    return clean === clean.split('').reverse().join('');
}

module.exports = { isPalindrome };