function longestSubarray(arr) {
    let n = arr.length;
    let maxLength = 0;
    let countZero = 0;
    let countOne = 0;
    let start = 0;
    let map = new Map();

    for (let i = 0; i < n; i++) {
        if (arr[i] === 0) {
            countZero++;
        } else {
            countOne++;
        }

        if (countZero === countOne) {
            if (i + 1 - start > maxLength) {
                maxLength = i + 1 - start;
            }
        } else {
            countZero = 0;
            countOne = 0;
            start = i + 1;
        }
    }

    return maxLength;
}

// Input handling
const [n, ...arr] = readline().split(' ');
n = parseInt(n);
arr = arr.map(x => parseInt(x));

console.log(longestSubarray(arr));