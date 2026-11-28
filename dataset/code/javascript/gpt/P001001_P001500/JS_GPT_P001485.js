// P001485 - Long Pressed Name
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const name = lines[0].trim();
    const typed = lines[1].trim();
    let i = 0, j = 0;
    while (j < typed.length) {
        if (i < name.length && name[i] === typed[j]) {
            i++;
            j++;
        } else if (j > 0 && typed[j] === typed[j - 1]) {
            j++;
        } else {
            console.log("NO");
            return;
        }
    }
    console.log(i === name.length ? "YES" : "NO");
}

main();
