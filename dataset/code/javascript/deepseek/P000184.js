const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
    let parts = line.split(' ');
    arr = parts.map(Number);
});

rl.on('close', function() {
    const longestSubarray = (function(arr, sum) {
        let currentSum = arr[0], maxLength = 0;
        const map = {0: arr[0]};

        for(let i = 1; i < arr.length; i++){
            currentSum += arr[i];
            if(map[currentSum - sum])
                maxLength = Math.max(maxLength, i - map[currentSum - sum]);
            else if(!map[currentSum])
                map[currentSum] = i;
        }
        return maxLength;
    })(arr, parseInt(arr[arr.length-1]));

    console.log(longestSubarray ? longestSubarray : 0);
    process.exit();
});