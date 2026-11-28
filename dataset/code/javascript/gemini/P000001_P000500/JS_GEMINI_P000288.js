function validPalindrome(s) {
    function isPali(l, r) {
        while (l < r) {
            if (s[l] !== s[r]) return false;
            l++; r--;
        }
        return true;
    }

    let i = 0, j = s.length - 1;
    while (i < j) {
        if (s[i] !== s[j]) {
            return isPali(i + 1, j) || isPali(i, j - 1);
        }
        i++; j--;
    }
    return true;
}

module.exports = { validPalindrome };