// P001488 - Minimum Length After Deleting Similar Ends
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let l = 0, r = s.length - 1;
    while (l < r && s[l] === s[r]) {
        const c = s[l];
        while (l <= r && s[l] === c) l++;
        while (l <= r && s[r] === c) r--;
    }
    console.log(r >= l ? r - l + 1 : 0);
}

main();
