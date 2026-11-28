Here is the JavaScript code:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
    var lines = input.split('\n');
    var N = parseInt(lines[0]);
    var K = parseInt(lines[1]);
    var array = lines[2].split(' ').map(Number);

    var maxSum = -Infinity;
    var dp = new Array(N + 1).fill(0).map(() => new Array(K + 1).fill(0));

    for(let i=0;i<N;i++){
        for(let j=0;j<=i;j++){
            for(let k=1;k<=j;k++){
                dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j] + array[i]);
           
                if(i >= K && j >= K){
                    maxSum = Math.max(maxSum, dp[i + 1][j + 1]);
                }
            }
       
            if(i >= K){
                dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], dp[i][j]);
            }
        }
    }

    console.log(maxSum);
});

This JavaScript code uses a dynamic programming approach to solve the problem. It first initializes a 3D array dp of size (N + 1)x(K + 1) and sets all elements to 0. It then iterates through each possible combination of elements in the array using a nested loop to ensure that the subarray length does not exceed K. For each combination, it updates the maximum sum. If the subarray length is greater than or equal to K, it also updates the maximum sum. At the end, it prints out the maximum sum.