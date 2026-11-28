// P001538 - Permutation in String
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s1 = input[0];
    const s2 = input[1];
    if (s2.length < s1.length) {
        console.log("NO");
        return;
    }
    const count1 = new Array(26).fill(0);
    const count2 = new Array(26).fill(0);
    for (let i = 0; i < s1.length; i++) {
        count1[s1.charCodeAt(i) - 97]++;
        count2[s2.charCodeAt(i) - 97]++;
    }
    function match() {
        for (let i = 0; i < 26; i++) {
            if (count1[i] !== count2[i]) return false;
        }
        return true;
    }
    if (match()) {
        console.log("YES");
        return;
    }
    for (let i = s1.length; i < s2.length; i++) {
        count2[s2.charCodeAt(i) - 97]++;
        count2[s2.charCodeAt(i - s1.length) - 97]--;
        if (match()) {
            console.log("YES");
            return;
        }
    }
    console.log("NO");
}

main();
