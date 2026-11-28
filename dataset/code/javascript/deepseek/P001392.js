const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = Number(rl.question()); // Read the number of cases

rl.close();

function countSubarrays(arr, k) {
  let count = 0;
  let prefixSum = {0: 1};
  let sum = 0;
  for(let num of arr) {
    sum += num;
    if(sum % k === 0) {
      count += prefixSum[sum / k];
    }
    if(!(sum in prefixSum)) {
      prefixSum[sum] = 0;
    }
    prefixSum[sum]++;
  }
  return count;
}

for(let i = 0; i < cases; i++) {
  rl.write(`Enter N and K (separated by space), then press enter: `);
  rl.readLine((err, input) => {
    if(err) {
      console.log(`ERROR: ${err}`);
      return;
    }
    let [N, K] = input.split(' ').map(Number);
    rl.write(`Enter the elements (separated by space), then press enter: `);
    let arr = rl.readLine((err, input) => {
      if(err) {
        console.log(`ERROR: ${err}`);
        return;
      }
      arr = input.split(' ').map(Number);
      console.log(`The number of subarrays divisible by ${K} is: `, countSubarrays(arr, K));
    });
  });
}