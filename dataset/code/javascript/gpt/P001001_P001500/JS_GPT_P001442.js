// P001442 - Find Duplicate Files by Content
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 1) return;
    const n = parseInt(lines[0].trim(), 10);
    const contentMap = new Map();
    for (let i = 1; i <= n && i < lines.length; i++) {
        const line = lines[i].trim();
        if (!line) continue;
        const parts = line.split(" ");
        const dir = parts[0];
        for (let j = 1; j < parts.length; j++) {
            const openIdx = parts[j].indexOf("(");
            const closeIdx = parts[j].indexOf(")");
            const filename = parts[j].substring(0, openIdx);
            const content = parts[j].substring(openIdx + 1, closeIdx);
            const fullPath = `${dir}/${filename}`;
            if (!contentMap.has(content)) contentMap.set(content, []);
            contentMap.get(content).push(fullPath);
        }
    }
    for (const group of contentMap.values()) {
        if (group.length > 1) {
            console.log(group.join(" "));
        }
    }
}

main();
