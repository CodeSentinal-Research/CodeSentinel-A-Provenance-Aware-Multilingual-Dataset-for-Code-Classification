function numIslands(grid) {
    let count = 0;
    let visited = new Array(grid.length).fill(0).map(() => new Array(grid[0].length).fill(0));

    function dfs(i, j) {
        if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]===0 || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i-1, j);
        dfs(i+1, j);
        dfs(i, j-1);
        dfs(i, j+1);
    }

    for(let i=0; i<grid.length; i++) {
        for(let j=0; j<grid[0].length; j++) {
            if(grid[i][j]===1 && visited[i][j]===false) {
                dfs(i, j);
                count++;
            }
        }
    }

    return count;
}