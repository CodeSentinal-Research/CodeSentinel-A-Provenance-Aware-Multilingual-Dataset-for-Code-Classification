let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [],
    K;

rl.on('line', function(line) {
    let parts = line.split(' ');
    arr = parts[1].split('').map(Number);
    K = parts[0];
    console.log(getCount(arr, K));
}).on('close', function() {
    process.exit();
});

function getCount(arr, K) {
    let count = 0,
        oddCount = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] % 2 !== 0)
            oddCount++;
        if (oddCount === K)
            count++;
        if (oddCount > K) {
            let temp = oddCount - K;
            oddCount = temp;
            if (arr[i] % 2 !== 0)
                count--;
        }
    }
    return count;
}
This code uses the readline module to read the inputs from the standard input. It first reads the array and K and then calls the getCount function. The getCount function checks each element in the array and increments the count and oddCount variables if the current element is odd. If the oddCount equals K, it increments the count. If the oddCount becomes greater than K, it decreases the count by one because it is not allowed to have K numbers following each other. Finally, it returns the count.