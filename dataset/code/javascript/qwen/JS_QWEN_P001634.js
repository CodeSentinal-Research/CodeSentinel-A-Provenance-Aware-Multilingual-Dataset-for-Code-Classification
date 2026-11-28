const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols, k] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let maxSum = -Infinity;
        for (let l = 0; l < cols; l++) {
            let temp = new Array(rows).fill(0);
            for (let r = l; r < cols; r++) {
                for (let i = 0; i < rows; i++) temp[i] += grid[i][r];
                
                // Max subarray sum <= k in temp
                let prefixSums = [0];
                let sum = 0;
                for (let x of temp) {
                    sum += x;
                    prefixSums.push(sum);
                }
                
                // Use TreeSet logic or sorted array to find best prefix
                // In JS, we can sort and binary search
                let sortedPrefixes = [];
                for (let p of prefixSums) {
                    // Find smallest prefix >= sum - k
                    let target = sum - k;
                    // Binary search in sortedPrefixes
                    let lo = 0, hi = sortedPrefixes.length;
                    while (lo < hi) {
                        let mid = Math.floor((lo + hi) / 2);
                        if (sortedPrefixes[mid] < target) lo = mid + 1;
                        else hi = mid;
                    }
                    if (lo < sortedPrefixes.length) {
                        maxSum = Math.max(maxSum, sum - sortedPrefixes[lo]);
                    }
                    
                    // Insert sum into sortedPrefixes
                    let insertIdx = lo; // Actually need to find correct spot for sum
                    // Re-do binary search for insertion
                    lo = 0; hi = sortedPrefixes.length;
                    while (lo < hi) {
                        let mid = Math.floor((lo + hi) / 2);
                        if (sortedPrefixes[mid] < sum) lo = mid + 1;
                        else hi = mid;
                    }
                    sortedPrefixes.splice(lo, 0, sum);
                }
            }
        }
        console.log(maxSum === -Infinity ? 0 : maxSum); // Problem says non-empty, so if all > k, what? Usually constraints ensure solution.
        rl.close();
    }
});
