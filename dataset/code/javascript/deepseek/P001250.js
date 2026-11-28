const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter the sorted array elements: ', (arr) => {
    arr = arr.split(' ').map(Number);

    let dp = new Array(n).fill(1);
    let dp2 = new Array(n).fill(1);
    let min = new Array(n).fill(0);
    let max = new Array(n).fill(0);

    for(let i = 1; i < n; i++) {
      if(arr[i] == arr[i-1] + 1) {
        dp[i] = dp[i-1] + 1;
      }
      min[i] = Math.min(min[i-1], dp[i]);
    }

    for(let i = n-2; i >= 0; i--) {
      if(arr[i] == arr[i+1] - 1) {
        dp2[i] = dp2[i+1] + 1;
      }
      max[i] = Math.max(max[i+1], dp2[i]);
    }

    let flag = false;
    for(let i = 0; i < n-2; i++) {
      if(max[i+2] >= dp[i] && min[i+2] >= dp[i]) {
        flag = true;
        break;
      }
    }

    if(flag) {
      console.log('YES');
    } else {
      console.log('NO');
    }

    rl.close();
  });
});