function minVisitedCells(m, n, grid) {
    let queue = [[0, 0, 0]];
    let visited = new Array(m).fill(0).map(() => new Array(n).fill(Infinity));
    visited[0][0] = 1;
    let dx = [0, 1];
    let dy = [1, 0];
    
    while(queue.length > 0) {
        let [x, y, step] = queue.shift();
        for(let i = 0; i < 2; i++) {
            let newX = x + dx[i], newY = y + dy[i];
            if(newX < m && newY < n && step + 1 < visited[newX][newY]) {
                visited[newX][newY] = step + 1;
                queue.push([newX, newY, step + 1]);
            }
        }
    }
    
    return visited[m-1][n-1] === Infinity ? -1 : visited[m-1][n-1];
}

The code first creates a 2D array 'visited' to store the minimum steps to reach each cell. The cell (0, 0) is initialized with 1 because there is one step to reach it. Then we use a Breadth-First Search (BFS) algorithm to find the minimum steps from the top-left cell to the bottom-right cell. If the destination cannot be reached, return -1.

Input: 2 integers m and n, and a 2D integer array grid. The function will return the minimum number of visited cells needed to reach the bottom-right cell.