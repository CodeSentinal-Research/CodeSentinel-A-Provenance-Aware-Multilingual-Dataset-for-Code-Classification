function longestTurbulentSubarray(arr) {
    let maxLen = 1;
    let currLen = 1;

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > arr[i-1]) {
            currLen++;
        } else {
            maxLen = Math.max(maxLen, currLen);
            currLen = 1;
        }
    }

    maxLen = Math.max(maxLen, currLen);
    return maxLen;
}

let input = process.argv[2] ? process.argv[2].split(',').map(n => parseInt(n)) : [5, 2, 4, 1, 3, 2, 4];
console.log(longestTurbulentSubarray(input));