const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        const nums1 = lines[1].split(/\s+/).map(Number);
        const nums2 = lines[2].split(/\s+/).map(Number);
        
        if (m > n) { console.log(findMedian(nums2, nums1, n, m)); rl.close(); return; }
        
        function findMedian(A, B, m, n) {
            let l = 0, r = m;
            while (l <= r) {
                let i = Math.floor((l + r) / 2);
                let j = Math.floor((m + n + 1) / 2) - i;
                if (i < m && B[j-1] > A[i]) l = i + 1;
                else if (i > 0 && A[i-1] > B[j]) r = i - 1;
                else {
                    let maxLeft = 0;
                    if (i === 0) maxLeft = B[j-1];
                    else if (j === 0) maxLeft = A[i-1];
                    else maxLeft = Math.max(A[i-1], B[j-1]);
                    
                    if ((m + n) % 2 === 1) return maxLeft;
                    
                    let minRight = 0;
                    if (i === m) minRight = B[j];
                    else if (j === n) minRight = A[i];
                    else minRight = Math.min(A[i], B[j]);
                    
                    return (maxLeft + minRight) / 2.0;
                }
            }
            return 0;
        }
        console.log(findMedian(nums1, nums2, m, n));
        rl.close();
    }
});
