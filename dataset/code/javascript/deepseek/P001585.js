process.stdin.resume();
process.stdin.on('data', function(data){
    var inputs = data.toString().split("\n");
    var N = parseInt(inputs[0].split(" ")[0]);
    var K = parseInt(inputs[0].split(" ")[1]);
    var arr = inputs[1].split(" ").map(Number);
    console.log(maxFrequency(arr, K));
});

function maxFrequency(arr, K) {
    let count = {};
    let max = 0;
    let min = Number.MAX_SAFE_INTEGER;

    for(let num of arr) {
        count[num] = (count[num] || 0) + 1;
        max = Math.max(max, count[num]);
        min = Math.min(min, num);
    }

    if(max - min > K) {
        let diff = max - min;
        K -= diff;
        if(K < 0) return max;
        max = 0;
        for(let num of arr) {
            if(num == min) max++;
            count[num]--;
        }
    }

    let freq = {};
    for(let num of arr) {
        freq[num] = (freq[num] || 0) + count[num];
        max = Math.max(max, freq[num]);
    }

    return max;
}
This JavaScript code reads the input data and outputs the maximum possible frequency after performing at most K operations.

In the `maxFrequency` function, we first count the frequency of each number in the array. Then, we find the difference between the maximum frequency and the smallest number. If this difference is greater than K, we can only increase the frequency of the smallest number by 1. Otherwise, we need to increase all the numbers with the same frequency by 1. Finally, we return the maximum frequency after all operations.