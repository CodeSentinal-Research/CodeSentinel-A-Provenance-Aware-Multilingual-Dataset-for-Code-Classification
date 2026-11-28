process.stdin.resume();
process.stdin.on('data', (chunk) => {
    const N = parseInt(chunk.toString().trim(), 10);
    const arr = process.stdin.read()
        .toString()
        .trim()
        .split(' ')
        .map(num => parseInt(num, 10));

    console.log(maxChunksToMakeSorted(arr, N));
});

function maxChunksToMakeSorted(arr, N) {
    let max = -Infinity;
    let chunks = 0;

    for (let i = 0; i < N; i++) {
        max = Math.max(max, arr[i]);

        if (max === i) {
            chunks++;
        }
    }

    return chunks;
}