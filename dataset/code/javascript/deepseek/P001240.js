// Read the number of intervals
const N = parseInt(readline());

let intervals = [];

// Read the intervals
for(let i = 0; i < N; i++) {
    const [start, end] = readline().split(' ').map(Number);
    intervals.push({start, end});
}

// Sort the intervals by start time
intervals.sort((a, b) => a.start - b.start);

let removed = 0;
let end = Number.MIN_SAFE_INTEGER;

// Check for overlapping intervals
for(let interval of intervals) {
    if(interval.start >= end) {
        end = interval.end;
    } else {
        removed++;
    }
}

// Print the number of removed intervals
console.log(removed);
This code reads the number of intervals and then the intervals themselves. It then sorts the intervals by start time. After that, it checks for overlapping intervals and increments the count if an overlap is found. The final count is then printed out.