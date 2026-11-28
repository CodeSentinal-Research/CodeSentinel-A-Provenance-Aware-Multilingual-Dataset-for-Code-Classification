process.stdin.resume();
process.stdin.on('data', (chunk) => {
  const n = parseInt(chunk.toString().trim(), 10);
  const arr = process.stdin.read().toString().trim().split(' ').map(num => parseInt(num, 10));

  let dp = new Array(n);
  dp[0] = {ei: arr[0] % 2 === 0, max: 1};

  let maxLen = 1;

  for(let i = 1; i < n; i++) {
    dp[i] = {ei: arr[i] % 2 === dp[i - 1].ei, max: dp[i - 1].max + (dp[i - 1].ei ? 1 : 0)};
    if(dp[i].max > maxLen) {
      maxLen = dp[i].max;
    }
  }
  
  console.log(maxLen);

  process.stdin.pause();
});
This JavaScript code reads the number of integers n, followed by the actual integers. It then utilizes dynamic programming (dp) to find the maximum length of an alternating even-odd subarray. The dp structure contains the current element's parity and the maximum length of the subarray ending at the current point. The maximum length is updated if the current length of the subarray is greater than the previously longest.