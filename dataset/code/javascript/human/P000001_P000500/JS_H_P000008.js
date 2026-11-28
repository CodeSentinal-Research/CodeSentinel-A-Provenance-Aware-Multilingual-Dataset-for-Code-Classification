function positiveNegativeZero(arr) {
    const len = arr.length;
    let positiveCount = 0;
    let negativeCount = 0;
    let zeroCount = 0;

    for (let i = 0; i < len; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        } else if (arr[i] === 0) {
            zeroCount++;
        }
    }

    console.log((positiveCount / len).toFixed(6));
    console.log((negativeCount / len).toFixed(6));
    console.log((zeroCount / len).toFixed(6));
}

const arr = [-4, 3, -9, 0, 4, 1]; // output: 0.500000   0.333333    0.166667
positiveNegativeZero(arr);
