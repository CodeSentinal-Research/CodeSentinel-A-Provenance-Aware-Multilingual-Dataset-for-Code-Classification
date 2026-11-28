// P001116 - Surrounded Regions
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const board = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(input[ptr++]);
        board.push(row);
    }
    function dfs(i, j) {
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] !== "O") return;
        board[i][j] = "E";
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
    for (let i = 0; i < r; i++) {
        if (board[i][0] === "O") dfs(i, 0);
        if (board[i][c - 1] === "O") dfs(i, c - 1);
    }
    for (let j = 0; j < c; j++) {
        if (board[0][j] === "O") dfs(0, j);
        if (board[r - 1][j] === "O") dfs(r - 1, j);
    }
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (board[i][j] === "O") board[i][j] = "X";
            else if (board[i][j] === "E") board[i][j] = "O";
        }
        console.log(board[i].join(" "));
    }
}

main();
