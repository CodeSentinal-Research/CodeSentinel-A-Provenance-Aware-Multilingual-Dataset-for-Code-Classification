Here is the JavaScript code to solve the problem:

let [N, arr] = process.argv.slice(2);
N = parseInt(N);
arr = arr.split(' ').map(num => parseInt(num));

let zeroes = [];
let ones = [];

for(let i = 0; i < arr.length; i++){
    if(arr[i] === 0){
        zeroes.push(arr[i]);
    }else{
        ones.push(arr[i]);
    }
}

console.log(zeroes.concat(ones));

This code reads the input from the command line arguments. It separates 0s and 1s and then prints the segregated array.

Please note, the input should be provided in the following format:

N
1 0 1 0 1 1

where N is the number of integers and the integers themselves.