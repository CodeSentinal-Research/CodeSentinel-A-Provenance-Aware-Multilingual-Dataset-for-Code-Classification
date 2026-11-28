// P001207 - Stone Game
const fs = require("fs");

function main() {
    const dominoes = fs.readFileSync(0, "utf8").trim();
    if (!dominoes) return;
    const n = dominoes.length;
    const forces = new Array(n).fill(0);
    let f = 0;
    for (let i = 0; i < n; i++) {
        if (dominoes[i] === "R") f = n;
        else if (dominoes[i] === "L") f = 0;
        else f = Math.max(0, f - 1);
        forces[i] += f;
    }
    f = 0;
    for (let i = n - 1; i >= 0; i--) {
        if (dominoes[i] === "L") f = n;
        else if (dominoes[i] === "R") f = 0;
        else f = Math.max(0, f - 1);
        forces[i] -= f;
    }
    let res = "";
    for (let i = 0; i < n; i++) {
        if (forces[i] > 0) res += "R";
        else if (forces[i] < 0) res += "L";
        else res += ".";
    }
    console.log(res);
}

main();
