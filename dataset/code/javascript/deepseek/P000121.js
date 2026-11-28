Here is the JavaScript code that solves the problem:

// Get input from user
let input = process.argv[2];
let arr = input.split(' ').map(Number);

// Function to find the majority element
function findMajorityElement(arr) {
    let count = 1;
    let majorityElement = arr[0];

    for(let i = 1; i < arr.length; i++) {
        if(arr[i] === majorityElement) {
            count++;
        } else {
            count--;
       
            if(count === 0) {
                majorityElement = arr[i];
                count = 1;
            }
        }
    }
    return majorityElement;
}

console.log(findMajorityElement(arr));

This program first reads the input from the user and splits it into an array of integers. Then it calls the `findMajorityElement` function, which finds the majority element in the array. The `findMajorityElement` function uses a variable `count` to keep track of the number of times a particular number appears in the array, and a variable `majorityElement` to store the majority number. For each number in the array, it checks if the current number is the same as the majority number. If it is, it increments the `count`. If it is different, it decrements the `count`. If the `count` becomes 0, it resets the `count` and updates the `majorityElement`. Finally, it returns the `majorityElement`.