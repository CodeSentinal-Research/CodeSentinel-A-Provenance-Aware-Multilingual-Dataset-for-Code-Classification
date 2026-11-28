process.stdin.setEncoding('utf8');

process.stdin.on('data', (data) => {
    const binaryArray = data.split(' ').map(Number);
    const maxConsecutiveOnes = findMaxConsecutiveOnes(binaryArray);
    process.stdout.write(`${maxConsecutiveOnes}\n`);
});

function findMaxConsecutiveOnes(binaryArray) {
    let maxCount = 0;
    let count = 0;

    for (let i = 0; i < binaryArray.length; i++) {
        if (binaryArray[i] === 1) {
            count++;
            maxCount = Math.max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}