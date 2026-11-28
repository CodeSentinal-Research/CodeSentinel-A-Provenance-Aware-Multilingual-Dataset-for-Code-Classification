Here is a JavaScript solution for the problem using recursion:

function exist(board, word) {
    const rowLen = board.length;
    const colLen = board[0].length;
    const wordLen = word.length;

    // Helper function to check if a word exists in the board
    function dfs(i, j, idx) {
        // If the word is completely traversed
        if (idx === wordLen) {
            return true;
        }

        // If the current character of the word does not match the current board cell
        // Or if the current cell is out of bounds
        if (i < 0 || j < 0 || i >= rowLen || j >= colLen || board[i][j] !== word[idx]) {
            return false;
        }

        // Mark the current cell as visited (we can't use it again)
        const temp = board[i][j];
        board[i][j] = "*";

        // Recursively check for the remaining characters
        const found = (dfs(i + 1, j, idx + 1) || dfs(i - 1, j, idx + 1) || dfs(i, j + 1, idx + 1) || dfs(i, j - 1, idx + 1));

        // Backtrack: remove the marked cell for other paths
        board[i][j] = temp;

        return found;
    }

    // Check all characters of the board
    for (let i = 0; i < rowLen; i++) {
        for (let j = 0; j < colLen; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}

This code uses depth-first search (DFS) to find the target word in the grid. It traverses all adjacent cells of the current cell and recursively checks for the remaining characters. If a character of the target word is found, it returns true. If the target word cannot be formed by traversing adjacent cells, it returns false.

The time complexity of the code is O(N×M^2) where N and M are the dimensions of the board. This is because we are doing a depth-first search of all possible paths from each cell in the board. The space complexity is O(N×M) for the recursion stack.