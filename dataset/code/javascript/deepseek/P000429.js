Here is the JavaScript code for the problem:

// Read input
let [N, target] = readline().split(' ').map(Number);
let arr = readline().split(' ').map(Number);

// Function to perform linear search
function linearSearch(arr, target) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) {
      return i;
    }
  }
  return -1;
}

// Call the function and print the result
let result = linearSearch(arr, target);
console.log(result);

In this code, we first read the input from the user. The first line is the number of elements in the array and the target element. The second line is the array itself.

The `linearSearch` function takes in an array and a target value. It then iterates through the array and returns the index of the target value if it is found. If the target is not found, it returns -1.

Finally, we call the `linearSearch` function with the provided input and print the result.