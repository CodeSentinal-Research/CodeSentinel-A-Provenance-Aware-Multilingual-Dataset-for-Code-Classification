// JavaScript solution for removing duplicates from a sorted array

function removeDuplicates(nums) {
    if(nums.length === 0) return 0;
    let i = 0;
    for(let j = 1; j < nums.length; j++) {
        if(nums[j] !== nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

// Input handling
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let nums = [];

rl.question('Enter the number of elements: ', (num) => {
    rl.question('Enter the elements: ', (elements) => {
        nums = elements.split(' ').map(Number);
        console.log(`New length after removing duplicates: ${removeDuplicates(nums)}`);
        rl.close();
    });
});