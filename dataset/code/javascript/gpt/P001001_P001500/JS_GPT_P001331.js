// P001331 - Restore IP Addresses
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const results = [];
    function backtrack(start, dots, path) {
        if (dots === 4 && start === s.length) {
            results.push(path.slice(0, -1));
            return;
        }
        if (dots === 4 || start === s.length) return;
        for (let len = 1; len <= 3 && start + len <= s.length; len++) {
            const part = s.substring(start, start + len);
            const val = parseInt(part, 10);
            if (val > 255 || (part.length > 1 && part[0] === "0")) break;
            backtrack(start + len, dots + 1, path + part + ".");
        }
    }
    backtrack(0, 0, "");
    for (const ip of results) console.log(ip);
}

main();
