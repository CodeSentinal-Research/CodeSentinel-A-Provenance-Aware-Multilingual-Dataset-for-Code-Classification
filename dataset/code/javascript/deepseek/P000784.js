Here is the JavaScript code:

function countOdds(nums, q) {
  let prefixSums = [0];
  for (let i = 0; i < nums.length; i++) {
    prefixSums[i + 1] = prefixSums[i] + (nums[i] % 2 !== 0 ? 1 : 0);
  }

  for (let i = 0; i < q; i++) {
    let [l, r] = readline().split(' ').map(Number);
    console.log(prefixSums[r + 1] - prefixSums[l]);
  }
}

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(data) {
  countOdds(data.split(', '), process.stdin.read().split('\n').length - 1);
});

In this code, `prefixSums` is an array that stores the count of odd numbers up to the current index in `nums`. For each number in `nums`, we add 1 to the corresponding index in `prefixSums` if the number is odd, otherwise we do nothing.

In the main part of the code, for each query `[L, R]`, we subtract the count of odd numbers from `prefixSums[R + 1]` to `prefixSums[L]` to get the count of odd numbers in the range `[L, R]`.