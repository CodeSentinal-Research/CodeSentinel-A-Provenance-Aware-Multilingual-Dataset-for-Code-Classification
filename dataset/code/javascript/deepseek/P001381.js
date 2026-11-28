Here is a simple JavaScript solution for the problem.

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Please enter the number of elements: ', (N) => {
    rl.question('Please enter the elements: ', (elements) => {
        let nums = elements.split(' ').map(Number);
        console.log(findLongestConsecutive(nums, N));
        rl.close();
    });
});

function findLongestConsecutive(nums, N) {
    let set = new Set(nums);
    let maxCount = 0;

    for(let num of set) {
        if (!set.has(num - 1)) {
            let count = 0;
            let currentNum = num;

            while (set.has(currentNum)) {
                count++;
                currentNum++;
            }

            maxCount = Math.max(maxCount, count);
        }
    }

    return maxCount;
}

This code first reads the number of elements from the user. Then it reads the elements of the array. It then uses the `findLongestConsecutive` function to find the longest consecutive sequence in the array. It uses a set to store the elements of the array so that it can quickly check if a number is in the set or not. Then it iterates through the set, and for each number, it checks if the number minus 1 is in the set. If it is, it increases the count and moves to the next number. It keeps track of the longest count and returns it at the end.