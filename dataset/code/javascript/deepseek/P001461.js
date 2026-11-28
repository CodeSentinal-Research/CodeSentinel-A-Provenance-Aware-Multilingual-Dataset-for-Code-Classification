Here is the JavaScript solution for the two sum problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.question('Enter number of elements: ', (num) => {
    rl.question('Enter elements (separated by space): ', (elements) => {
        arr = elements.split(' ').map(Number);
        let target = parseInt(elements.split(' ').pop());
        let result = twoSum(arr, target);
        console.log(`Indices are ${result[0]} and ${result[1]}`);
        rl.close();
    });
});

function twoSum(nums, target) {
    let map = {};
    for(let i = 0; i < nums.length; i++) {
        if(map[nums[i]] !== undefined) {
            return [map[nums[i]], i];
        }
        map[target - nums[i]] = i;
    }
}

This code reads the number of elements and the elements, then the target number. It uses a map to store the numbers that have been seen so far, and for each number, it checks if the difference between the target and the current number is in the map. If it is, it returns the indices of the two numbers. If it is not, it adds the current number and its index to the map. This is done in a single pass over the array, so the time complexity is O(n).