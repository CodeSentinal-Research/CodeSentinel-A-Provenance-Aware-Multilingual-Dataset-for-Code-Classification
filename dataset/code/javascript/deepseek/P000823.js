Here is the JavaScript code:

function findKthPositive(nums, k) {
  let i = 0;
  let count = 0;
  let num = 1;

  while (count < k) {
    if (!nums.includes(num)) {
      count++;
    }
    if (count === k) {
      return num;
    }
    num++;
  }
}
This function works by iterating through the provided sorted array, incrementing a `num` variable until we reach a positive integer that is not in the array. It then counts how many missing positive integers we've found and stops when we've reached `k` of them.