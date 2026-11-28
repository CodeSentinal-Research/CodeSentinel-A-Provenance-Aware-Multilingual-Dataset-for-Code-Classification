Here is the JavaScript code for the given problem:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');

let N = parseInt(lines[0].split(' ')[0]);
let X = parseInt(lines[0].split(' ')[1]);

let arr = lines[1].split(' ').map(Number);

let count = 0;
for(let i = 0; i < arr.length; i++) {
    if(arr[i] !== X) {
        arr[count] = arr[i];
        count++;
    }
}

console.log(count);
for(let i = 0; i < count; i++) {
    console.log(arr[i]);
}
This code first reads the number of elements and the value to be removed from the input. Then it reads the array elements. After that, it iterates over the array and if the element is not equal to the value to be removed, it adds it to the next available position in the array, and increments the count. Finally, it prints the count and the array elements.