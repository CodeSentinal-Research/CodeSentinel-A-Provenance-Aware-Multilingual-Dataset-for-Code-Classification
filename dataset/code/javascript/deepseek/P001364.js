const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements (N) and K: ', (N) => {
    rl.question('Enter the elements: ', (elements) => {
        let nums = elements.split(' ').map(Number);
        let K = parseInt(N);

        const dp = new Array(K + 1).fill(0);
        const w = new Array(K + 1).fill(0);

        for (let i = 1; i <= N; i++) {
            w[i] = nums[i - 1];
        }

        for (let k = 1; k <= K; k++) {
            for (let n = k; n <= N; n++) {
                if (w[k] + nums[n - 1] > dp[k - 1] && w[k] + nums[n - 1] < dp[k]) {
                    dp[k] = w[k] + nums[n - 1];
                }
                if (w[k] + nums[n - 1] == dp[k]) {
                    dp[k] = Math.max(dp[k], dp[k - 1], w[k] + nums[n - 1]);
                }
            }
        }

        console.log('Minimum possible maximum subset sum:', dp[K]);

        rl.close();
    });
});

In this code, we use dynamic programming (DP) to solve the K-partition problem. We create two arrays, `dp` and `w`, to store the maximum sum of the subsets and the weights of the numbers, respectively. The `dp` array stores the maximum sum of the subsets for each `k` (from 1 to `K`), and the `w` array stores the weights of the numbers. We iterate through all possible combinations of partitions, and update the maximum sum for each partition. Finally, we print the minimum possible maximum subset sum.