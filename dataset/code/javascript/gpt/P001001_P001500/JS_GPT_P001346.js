// P001346 - Crossword Puzzle Solver
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 10) return;
    const grid = [];
    for (let i = 0; i < 10; i++) grid.push(lines[i].split(""));
    const words = lines[10].trim().split(";");
    function canPlaceH(r, c, word) {
        if (c + word.length > 10) return false;
        for (let i = 0; i < word.length; i++) {
            if (grid[r][c + i] !== "-" && grid[r][c + i] !== word[i]) return false;
        }
        return true;
    }
    function placeH(r, c, word) {
        const placed = [];
        for (let i = 0; i < word.length; i++) {
            if (grid[r][c + i] === "-") {
                grid[r][c + i] = word[i];
                placed.push([r, c + i]);
            }
        }
        return placed;
    }
    function canPlaceV(r, c, word) {
        if (r + word.length > 10) return false;
        for (let i = 0; i < word.length; i++) {
            if (grid[r + i][c] !== "-" && grid[r + i][c] !== word[i]) return false;
        }
        return true;
    }
    function placeV(r, c, word) {
        const placed = [];
        for (let i = 0; i < word.length; i++) {
            if (grid[r + i][c] === "-") {
                grid[r + i][c] = word[i];
                placed.push([r + i, c]);
            }
        }
        return placed;
    }
    function solve(wIdx) {
        if (wIdx === words.length) return true;
        const w = words[wIdx];
        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 10; j++) {
                if (canPlaceH(i, j, w)) {
                    const pl = placeH(i, j, w);
                    if (solve(wIdx + 1)) return true;
                    for (const [pr, pc] of pl) grid[pr][pc] = "-";
                }
                if (canPlaceV(i, j, w)) {
                    const pl = placeV(i, j, w);
                    if (solve(wIdx + 1)) return true;
                    for (const [pr, pc] of pl) grid[pr][pc] = "-";
                }
            }
        }
        return false;
    }
    solve(0);
    for (let i = 0; i < 10; i++) console.log(grid[i].join(""));
}

main();
