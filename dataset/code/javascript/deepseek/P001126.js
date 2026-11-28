Sure, here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = [];

rl.on('line', (line) => {
    testCases.push(line);
}).on('close', () => {
    for(let i=0; i<testCases.length; i++){
        let [R,C] = testCases[i].split(' ').map(x => parseInt(x));
        let grid = [];
        for(let j=0; j<R; j++){
            grid[j] = readline().split(' ').map(x => parseInt(x));
        }
        console.log(minEffortPath(grid, R, C));
    }
    rl.close();
});

function minEffortPath(grid, R, C){
    let efforts = new Array(R).fill(0).map(() => new Array(C).fill(0));
    let queue = [[0, 0]];
    efforts[0][0] = grid[0][0];
    let dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    while(queue.length){
        let [x, y] = queue.shift();
        for(let dir of dirs){
            let nx = x + dir[0], ny = y + dir[1];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                let newEffort = Math.max(efforts[x][y], Math.abs(grid[x][y] - grid[nx][ny]));
                if(newEffort < efforts[nx][ny]) {
                    efforts[nx][ny] = newEffort;
                    queue.push([nx, ny]);
                }
            }
        }
    }
    return efforts[R-1][C-1];
}

This code first reads the input and stores it in an array of tests. Then it iterates over each test, reads the grid and calculates the minimum effort path. The effort is stored in an 2D array and the queue is used to find all adjacent cells with the minimum effort.