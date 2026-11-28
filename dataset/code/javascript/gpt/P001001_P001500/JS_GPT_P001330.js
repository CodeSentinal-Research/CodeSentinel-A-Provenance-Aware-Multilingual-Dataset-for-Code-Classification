// P001330 - Palindrome Partitioning
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    function isPalindrome(sub) {
        let l = 0, r = sub.length - 1;
        while (l < r) {
            if (sub[l++] !== sub[r--]) return false;
        }
        return true;
    }
    const results = [];
    function backtrack(start, path) {
        if (start === s.length) {
            results.push([...path]);
            return;
        }
        for (let end = start + 1; end <= s.length; end++) {
            const sub = s.substring(start, end);
            if (isPalindrome(sub)) {
                path.push(sub);
                backtrack(end, path);
                path.pop();
            }
        }
    }
    backtrack(0, []);
    for (const part of results) console.log(part.join(" "));
}

main();
