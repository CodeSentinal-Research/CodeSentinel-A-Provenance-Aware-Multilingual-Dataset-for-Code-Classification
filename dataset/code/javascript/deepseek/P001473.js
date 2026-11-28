Here is the JavaScript code for the problem:

function threeSumClosest(nums, target) {
  nums.sort((a, b) => a - b);
  let closest = nums[0] + nums[1] + nums[nums.length - 1];

  for (let i = 0; i < nums.length - 2; i++) {
    let left = i + 1;
    let right = nums.length - 1;
    while (left < right) {
      let sum = nums[i] + nums[left] + nums[right];
      if (Math.abs(target - sum) < Math.abs(target - closest)) {
        closest = sum;
      }
      sum < target ? left++ : right--;
    }
  }

  return closest;
}

This code first sorts the input array. Then, for each element in the array, it finds two other elements in the array such that their sum is closest to the target. If the sum of the three numbers is less than the current closest sum, then it updates the closest sum. This process is done by using a two-pointer technique.

Note that this code assumes that the input array will have at least three distinct integers. If the input array has less than three integers, the code will not return a correct result.