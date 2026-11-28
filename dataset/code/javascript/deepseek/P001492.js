let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
  arr = line.split(' ');
});

rl.on('close', function() {
  let n = parseInt(arr[0]);
  let k = parseInt(arr[1]);
  let x = parseInt(arr[2]);

  rl.setPrompt('Enter ' + n + ' numbers: ');

  let nums = [];
  rl.on('line', function(line) {
    nums.push(parseInt(line));
    if(nums.length === n) {
      rl.close();
      findClosestElements(nums, x, k);
    }
  });
});

function findClosestElements(nums, x, k) {
  nums.sort((a, b) => a - b);
  let closest = [];
  for(let i = 0; i < nums.length; i++) {
    let left = binarySearch(nums, x - k, i, nums.length - 1);
    let right = binarySearch(nums, x + k, i, nums.length - 1);
    if(left !== -1 && right !== -1) {
      closest[closest.length] = nums[left];
      closest[closest.length] = nums[right];
      if(closest[closest.length - 1] > x) {
        closest[closest.length - 1] = x;
      }
    } else if(left !== -1) {
      closest[closest.length] = nums[left];
    } else if(right !== -1) {
      closest[closest.length] = nums[right];
    }
  }

  closest.sort((a, b) => a - b);

  console.log(`Closest elements to ${x} are: ${closest}`);
}

function binarySearch(nums, target, start, end) {
  if(start > end) {
    return -1;
  }
  let mid = Math.floor((start + end) / 2);
  if(nums[mid] == target) {
    return mid;
  } else if(nums[mid] > target) {
    return binarySearch(nums, target, start, mid - 1);
  } else {
    return binarySearch(nums, target, mid + 1, end);
  }
}

In this JavaScript code, we first read the input from the readline module. The first line is read and parsed into variables `n`, `k`, and `x`. The next lines are read and pushed into an array `nums`.

Then, we use a binary search to find the closest elements to `x`. The `binarySearch` function uses the binary search algorithm to find the closest element. If the target value is greater than the mid element, it checks in the right half of the array; if the target value is smaller, it checks in the left half.

Finally, we sort the closest elements and print them out.