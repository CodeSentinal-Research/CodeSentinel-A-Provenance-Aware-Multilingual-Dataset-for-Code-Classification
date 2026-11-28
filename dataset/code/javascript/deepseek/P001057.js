Here is the JavaScript code to solve the given problem. This code uses the concept of frequency count and sorting.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs = line.split(' ').map(Number);
    rl.close();
});

rl.on('close', function() {
    console.log(maxDistinctElements(inputs[0], inputs[1]));
});

function maxDistinctElements(N, K) {
    const freq = {};
    const arr = [];

    // Count frequency of each element
    for (let i = 0; i < N; i++) {
        const num = arr[i] = parseInt(readline().trim());
        if (freq[num]) freq[num]++;
        else arr.push(num);
    }

    // Sort the array in descending order of frequency
    arr.sort((a, b) => freq[b] - freq[a]);

    // Remove elements K times
    for (let i = 0; i < N; i++) {
        if (freq[arr[i]] <= K) {
            freq[arr[i]] = 0;
            K -= freq[arr[i]];
            if (K <= 0) break;
        }
    }

    // Count the remaining distinct elements
    let count = 0;
    for (let i = 0; i < N; i++) {
        if (freq[arr[i]] > 0) count++;
    }

    return count;
}

In this code, we create an object `freq` to count the frequency of each element in the array. We also create an array `arr` to store the elements of the array. The first line reads the number of elements N and the number of removals K. The rest of the lines read the elements of the array.

We then sort the array in descending order of frequency. After sorting, we remove elements K times. The remaining elements are counted and returned as the maximum possible number of distinct elements.