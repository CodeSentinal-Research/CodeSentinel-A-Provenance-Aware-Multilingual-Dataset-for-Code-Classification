// P001500 - Longest Palindromic Subsequence After One Removal
const fs = require("fs");

function isPalindrome(s, l, r) {
    while (l < r) {
        if (s[l] !== s[r]) return false;
        l++;
        r--;
    }
    return true;
}

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let l = 0, r = s.length - 1;
    while (l < r) {
        if (s[l] !== s[r]) {
            if (isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1)) {
                console.log("YES");
            } else {
                console.log("NO");
            }
            return;
        }
        l++;
        r--;
    }
    console.log("YES");
}

main();
