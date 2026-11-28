// P001447 - Sentence Similarity II
const fs = require("fs");

class DSU {
    constructor() {
        this.parent = new Map();
    }
    find(i) {
        if (!this.parent.has(i)) this.parent.set(i, i);
        if (this.parent.get(i) !== i) {
            this.parent.set(i, this.find(this.parent.get(i)));
        }
        return this.parent.get(i);
    }
    union(i, j) {
        const rootI = this.find(i);
        const rootJ = this.find(j);
        if (rootI !== rootJ) {
            this.parent.set(rootI, rootJ);
        }
    }
}

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 3) return;
    const s1 = lines[0].trim().split(/\s+/);
    const s2 = lines[1].trim().split(/\s+/);
    const p = parseInt(lines[2].trim(), 10);
    if (s1.length !== s2.length) {
        console.log("NO");
        return;
    }
    const dsu = new DSU();
    for (let i = 3; i < 3 + p && i < lines.length; i++) {
        const line = lines[i].trim();
        if (!line) continue;
        const [w1, w2] = line.split(/\s+/);
        dsu.union(w1, w2);
    }
    for (let i = 0; i < s1.length; i++) {
        const w1 = s1[i], w2 = s2[i];
        if (w1 !== w2 && dsu.find(w1) !== dsu.find(w2)) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
