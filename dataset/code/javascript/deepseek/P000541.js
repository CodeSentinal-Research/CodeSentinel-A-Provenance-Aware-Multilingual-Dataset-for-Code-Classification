function rottingOranges(grid) {
    let queue = [];
    let fresh = 0;
    let directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]; // right, left, down, up

    // count the number of fresh oranges
    for(let i = 0; i < grid.length; i++) {
        for(let j = 0; j < grid[i].length; j++) {
            if(grid[i][j] === 1) fresh++;
            else if(grid[i][j] === 2) queue.push([i, j]);
        }
    }

    // if there are no fresh oranges, return 0
    if(fresh === 0) return 0;

    let time = 0;
    while(queue.length > 0) {
        let len = queue.length;
        for(let i = 0; i < len; i++) {
            let cell = queue.shift();
            for(let j = 0; j < directions.length; j++) {
                let x = cell[0] + directions[j][0];
                let y = cell[1] + directions[j][1];
                if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] !== 1) continue;
                fresh--;
                if(fresh === 0) return time + 1;
                grid[x][y] = 2;
                queue.push([x, y]);
            }
        }
        time++;
    }

    // if there are still fresh oranges, return -1
    if(fresh > 0) return -1;

    return time;
}