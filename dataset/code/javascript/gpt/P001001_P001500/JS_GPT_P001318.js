// P001318 - Word Search
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const board = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(input[ptr++]);
        board.push(row);
    }
    const word = input[ptr++];
    function dfs(i, j, idx) {
        if (idx === word.length) return true;
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] !== word[idx]) return false;
        const temp = board[i][j];
        board[i][j] = "#";
        const found = dfs(i + 1, j, idx + 1) || dfs(i - 1, j, idx + 1) ||
                      dfs(i, j + 1, idx + 1) || dfs(i, j - 1, idx + 1);
        board[i][j] = temp;
        return found;
    }
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (board[i][j] === word[0] && dfs(i, j, 0)) {
                console.log("YES");
                return;
            }
        }
    }
    console.log("NO");
}

main();
