Here is the JavaScript code for the problem:

let n = parseInt(readline());
let arr = readline().split(' ').map(Number);

let maxLength = 0;
let currentLength = 1;

for(let i = 1; i < n; i++) {
    if(arr[i] < arr[i-1]) {
        currentLength++;
    } else {
        if(currentLength > maxLength) {
            maxLength = currentLength;
        }
        currentLength = 1;
    }
}

if(currentLength > maxLength) {
    maxLength = currentLength;
}

console.log(maxLength);

In this code, we first read the number of elements in the array from the first line. Then we read the array elements from the second line.

We initialize two variables, `maxLength` and `currentLength`, to 0 and 1, respectively. The `maxLength` will keep track of the length of the longest decreasing subarray found so far, while the `currentLength` will keep track of the current length of the subarray we're examining.

Then we iterate over the array, starting from the second element. If the current element is less than the previous element, we increment the `currentLength`. But if the current element is greater than or equal to the previous element, we check if `currentLength` is longer than `maxLength`, and if it is, update `maxLength` to be equal to `currentLength`. Then we reset `currentLength` to 1.

Finally, we print out `maxLength`, which is the length of the longest decreasing subarray.