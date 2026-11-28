Here is the JavaScript code for the problem:

// read the number of elements and elements
const N = parseInt(readline());
const nums = readline().split(' ').map(Number);

// sort the array
nums.sort((a, b) => a - b);

// loop over the array
for(let i = 0; i < nums.length; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;

    let left = i + 1;
    let right = nums.length - 1;

    while (left < right) {
        const sum = nums[i] + nums[left] + nums[right];

        if (sum === 0) {
            console.log(`${nums[i]} ${nums[left]} ${nums[right]}`);
            left++;
            right--;
            while (left < right && nums[left] === nums[left - 1]) left++;
            while (left < right && nums[right] === nums[right + 1]) right--;
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
}

This code first reads the number of elements and the elements themselves. It then sorts the array and loops over it, printing all unique triplets in lexicographical order. The code uses two pointers (left and right) to find the triplets, and it continues until the left pointer is not less than the right pointer.