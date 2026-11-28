Here is the JavaScript code for the given problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter elements: ', (str_nums) => {
    const nums = str_nums.split(' ').map(Number);

    let count = 0;
    for(let i = 0; i < nums.length; i++){
        for(let j = i + 1; j < nums.length; j++){
            if(nums[i] > nums[j]){
                count++;
            }
        }
    }

    console.log('Number of inversions: ', count);

    rl.close();
  });
});

This program uses readline module in Node.js to read the input from the standard input (keyboard). It starts by asking for the number of elements. Then it asks for the elements one by one. It splits the input string into an array of numbers using the split() method and maps each element to a number using the map() method. It then iterates over the array to count the inversions.