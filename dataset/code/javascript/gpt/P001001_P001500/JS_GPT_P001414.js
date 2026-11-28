// P001414 - Count Distinct Absolute Values
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const creators = [];
    for (let i = 0; i < n; i++) creators.push(input[ptr++]);
    const ids = [];
    for (let i = 0; i < n; i++) ids.push(input[ptr++]);
    const views = [];
    for (let i = 0; i < n; i++) views.push(parseInt(input[ptr++], 10));

    const totalViews = new Map();
    const bestVideo = new Map();

    for (let i = 0; i < n; i++) {
        const c = creators[i], id = ids[i], v = views[i];
        totalViews.set(c, (totalViews.get(c) || 0) + v);
        if (!bestVideo.has(c)) {
            bestVideo.set(c, { id, views: v });
        } else {
            const cur = bestVideo.get(c);
            if (v > cur.views || (v === cur.views && id < cur.id)) {
                bestVideo.set(c, { id, views: v });
            }
        }
    }

    let maxViews = -1;
    for (const v of totalViews.values()) {
        if (v > maxViews) maxViews = v;
    }

    const res = [];
    for (const [c, v] of totalViews.entries()) {
        if (v === maxViews) {
            res.push(`${c} ${bestVideo.get(c).id}`);
        }
    }
    res.sort();
    for (const line of res) console.log(line);
}

main();
