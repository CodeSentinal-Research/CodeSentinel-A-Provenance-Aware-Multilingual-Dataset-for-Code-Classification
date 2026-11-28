const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        // Binary search on effort
        let l=0, rVal=1000000, ans=1000000;
        while(l<=rVal) {
            let mid = Math.floor((l+rVal)/2);
            if(canReach(mid)) {
                ans = mid;
                rVal = mid-1;
            } else {
                l = mid+1;
            }
        }
        console.log(ans);
        rl.close();
        
        function canReach(limit) {
            let visited = Array.from({length: r}, () => new Array(c).fill(false));
            let queue = [[0,0]];
            visited[0][0] = true;
            let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
            while(queue.length > 0) {
                let [i, j] = queue.shift();
                if(i===r-1 && j===c-1) return true;
                for(let [di, dj] of dirs) {
                    let ni = i+di, nj = j+dj;
                    if(ni>=0 && ni<r && nj>=0 && nj<c && !visited[ni][nj] && Math.abs(grid[i][j]-grid[ni][nj])<=limit) {
                        visited[ni][nj] = true;
                        queue.push([ni, nj]);
                    }
                }
            }
            return false;
        }
    }
});
