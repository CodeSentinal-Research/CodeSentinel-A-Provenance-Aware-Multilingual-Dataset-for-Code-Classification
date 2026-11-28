Here is the code to solve this problem in JavaScript:

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let count = {};
    for(let num of nums) {
        count[num] = (count[num] || 0) + 1;
    }
    for(let num in count) {
        if(count[num] === 1) {
            return num;
        }
    }
};

This code works by using a JavaScript object (`count`) to keep track of the number of occurrences of each number in the input array. The `singleNumber` function then loops over the keys of `count` (which represent the unique numbers in the input array), and if the count for a number is 1 (indicating it only appeared once), it returns that number.

The time complexity of this solution is O(n), where n is the size of the input array. This is because it loops over the input array twice (once to create the `count` object and once to look for the single number). The space complexity is also O(n), because in the worst case, all elements in the input array will be unique, so the `count` object will store all elements in the input array.