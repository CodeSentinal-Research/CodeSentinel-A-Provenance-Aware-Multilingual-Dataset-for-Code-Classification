let N = parseInt(readline());
let arr = readline().split(' ').map(Number);

arr.sort((a, b) => a - b);

let evenIndex = 0;
let oddIndex = arr.length - 1;
let result = new Array(arr.length);

for (let num of arr) {
    if (num % 2 == 0) {
        result[evenIndex++] = num;
    } else {
        result[oddIndex--] = num;
    }
}

console.log(result.join(' '));