process.stdin.setEncoding('utf8');

process.stdin.on('data', function(data) {
    const inputs = data.split('\n');
    const N = parseInt(inputs[0]);
    const binaryArray = inputs[1].split(' ').map(Number);

    let maxLen = 0;
    let curLen = 0;
    let countZeros = 0;
    let countOnes = 0;

    for (let i = 0; i < N; i++) {
        const binary = binaryArray[i];

        if (binary === 0) {
            countZeros++;
        } else {
            countOnes++;
        }

        if (countZeros === countOnes) {
            if (curLen > maxLen) {
                maxLen = curLen;
            }
            countZeros = 0;
            countOnes = 0;
            curLen = 0;
        } else {
            curLen++;
        }
    }

    console.log(maxLen);
});