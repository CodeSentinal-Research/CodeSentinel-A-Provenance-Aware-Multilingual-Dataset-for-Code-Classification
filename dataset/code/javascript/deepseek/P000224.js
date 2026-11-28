Here is the JavaScript code to solve the Job Sequencing Problem:

// Read input from standard input
let n = parseInt(process.stdin.readline());
let jobs = [];
for (let i = 0; i < n; i++) {
    let [id, deadline, profit] = process.stdin.readline().trim().split(' ');
    jobs.push({ id, deadline: parseInt(deadline), profit: parseInt(profit) });
}

// Sort jobs based on deadline
jobs.sort((a, b) => b.deadline - a.deadline);

let maxProfit = 0;
let maxProfitJobs = 0;

for (let job of jobs) {
    if (job.deadline <= maxProfit) {
        maxProfit += job.profit;
        maxProfitJobs++;
    }
}

// Print result to standard output
console.log(maxProfit, maxProfitJobs);

This code reads the number of jobs from standard input, then reads the details of each job from standard input. The jobs are sorted by their deadlines in descending order.

It then iterates over the sorted jobs, checking if the current job's deadline is less than or equal to the maximum profit we've already achieved (which is zero at the start). If it is, it adds the current job's profit to our total profit and increments our count of jobs done.

Finally, it prints the total profit and the count of jobs done to standard output.