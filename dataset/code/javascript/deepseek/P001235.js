let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());

let jobs = [];
let maxProfit = 0;

rl.setPrompt('Enter deadline and profit separated by space, for example: 3 10');

for(let i = 0; i < N; i++) {
    let input = rl.readline('');
    let job = input.split(' ').map(Number);
    jobs.push(job);
}

jobs.sort((a, b) => a[1] - b[1]); // sort by profit in descending order

let currentTime = 0;

for(let i = 0; i < N; i++) {
    if(currentTime <= jobs[i][0]) {
        currentTime += jobs[i][1];
        maxProfit += jobs[i][1];
    }
}

console.log(maxProfit);

This JavaScript code reads the number of jobs from the input, then reads each job's deadline and profit. The jobs are sorted by profit in descending order. The algorithm then iterates through the sorted jobs, and if the current time is less than or equal to the job's deadline, it adds the job's profit to the total profit and adds the job's profit to the current time. At the end, it prints the maximum obtainable profit.