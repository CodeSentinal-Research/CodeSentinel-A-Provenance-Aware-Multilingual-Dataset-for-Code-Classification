process.stdin.resume();
process.stdin.on('data', function(data) {
    const [R, ...rows] = data.toString().split('\n').map(Number);
    let minBricks = Infinity;
    let totalBricks = 0;
    for(let i = 0; i < R; i++) {
        const [brickCount, ...bricks] = rows[i].split(' ').map(Number);
        totalBricks += brickCount;
        minBricks = Math.min(minBricks, ...bricks);
    }
    console.log(totalBricks - minBricks);
    process.stdin.pause();
});