// P001516 - Maximum White Tiles Covered by a Carpet
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const carpetLen = parseInt(input[1], 10);
    let ptr = 2;
    const tiles = [];
    for (let i = 0; i < n; i++) {
        tiles.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    }
    tiles.sort((a, b) => a[0] - b[0]);
    let maxCover = 0, cover = 0, r = 0;
    for (let l = 0; l < n; l++) {
        while (r < n && tiles[r][1] < tiles[l][0] + carpetLen) {
            cover += tiles[r][1] - tiles[r][0] + 1;
            r++;
        }
        if (r < n && tiles[r][0] < tiles[l][0] + carpetLen) {
            const partial = tiles[l][0] + carpetLen - tiles[r][0];
            maxCover = Math.max(maxCover, cover + partial);
        } else {
            maxCover = Math.max(maxCover, cover);
        }
        cover -= tiles[l][1] - tiles[l][0] + 1;
    }
    console.log(maxCover);
}

main();
