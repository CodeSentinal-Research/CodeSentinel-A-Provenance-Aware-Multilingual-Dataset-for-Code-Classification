const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.question('Enter the size of the array: ', (n) => {
    N = parseInt(n);
    let arr = [];
    rl.setEncoding('utf8');
    rl.question('Enter array elements: ', (input) => {
        arr = input.split(' ').map(Number);
        console.log(minSwaps(arr, N));
        rl.close();
    });
});

function minSwaps(arr, N) {
    let map = new Map(arr.map((e, i) => [e, i]));
    arr.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < N; i++) {
        if (map.get(arr[i]) !== i) {
            let j = i;
            while (map.get(arr[j]) !== j) {
                let k = map.get(arr[j]);
                [arr[j], arr[k]] = [arr[k], arr[j]];
                map.set(arr[j], j);
                map.set(arr[k], j);
                ans++;
            }
        }
    }
    return ans;
}
This code reads the size of the array and the array elements from the user. It then finds the minimum number of swaps to group all 1s together using a modified version of the QuickSort algorithm. The time complexity is O(n log n) due to the sorting operation. The space complexity is O(n) for storing the input array.