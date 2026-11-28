// Read input from the user
let N = parseInt(readline());
let target = parseInt(readline());
let arr = new Array(N).fill(null).map(Number);
arr = arr.map(parseInt);

// Count occurrences using linear search
let count = 0;
for(let i = 0; i < N; i++) {
    if(arr[i] === target) {
        count++;
    }
}

// Print the count
console.log(count);