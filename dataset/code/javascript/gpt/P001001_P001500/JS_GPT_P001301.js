// P001301 - Maximum Meetings in One Room
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const meetings = [];
    for (let i = 0; i < n; i++) {
        const s = parseInt(input[ptr++], 10);
        const f = parseInt(input[ptr++], 10);
        meetings.push({ id: i + 1, s, f });
    }
    meetings.sort((a, b) => (a.f !== b.f ? a.f - b.f : a.id - b.id));
    const selected = [];
    let lastEnd = -1;
    for (const m of meetings) {
        if (m.s > lastEnd) {
            selected.push(m.id);
            lastEnd = m.f;
        }
    }
    console.log(selected.join(" "));
}

main();
