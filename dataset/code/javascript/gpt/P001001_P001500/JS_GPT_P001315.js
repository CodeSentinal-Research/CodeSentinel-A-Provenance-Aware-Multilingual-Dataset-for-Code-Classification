// P001315 - Rat in a Maze
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const maze = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) row.push(parseInt(input[ptr++], 10));
        maze.push(row);
    }
    const paths = [];
    const visited = Array.from({ length: n }, () => new Array(n).fill(false));
    function solve(r, c, path) {
        if (r === n - 1 && c === n - 1) {
            paths.push(path);
            return;
        }
        visited[r][c] = true;
        const moves = [["D", 1, 0], ["L", 0, -1], ["R", 0, 1], ["U", -1, 0]];
        for (const [dir, dr, dc] of moves) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && maze[nr][nc] === 1 && !visited[nr][nc]) {
                solve(nr, nc, path + dir);
            }
        }
        visited[r][c] = false;
    }
    if (maze[0][0] === 1 && maze[n - 1][n - 1] === 1) solve(0, 0, "");
    if (paths.length > 0) {
        paths.sort();
        console.log(paths.join(" "));
    } else {
        console.log("-1");
    }
}

main();
