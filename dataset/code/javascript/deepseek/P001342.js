function solve() {
    let [N, K] = readline().split(' ').map(Number);
    let arr = readline().split(' ').map(Number);

    let subsequences = new Array(N + 1 - K + 1).fill(0).map((_, i) => i);

    for(let i = 0; i < N; i++) {
        for(let j = i + 1; j < N; j++) {
            if(arr[j] > arr[i]) {
                subsequences[j] = arr[j];
            }
        }
    }

    subsequences.sort((a, b) => a - b).forEach((subsequence, index) => {
        if(subsequence !== subsequences[0]) {
            console.log();
        }
        console.log(subsequence);
    });
}

function readline() {
    return require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    }).readLine();
}

solve();
This code reads the input and generates all increasing subsequences of length K. It uses a sliding window approach to find all increasing subsequences of length K. The main idea is to find all numbers in the array that are greater than the current number, and use those as potential new numbers in the subsequences. After finding all possible subsequences, it sorts them and prints them.