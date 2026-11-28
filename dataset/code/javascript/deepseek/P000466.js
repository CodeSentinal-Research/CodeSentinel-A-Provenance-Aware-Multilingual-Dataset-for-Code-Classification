// read input
let n = parseInt(readline());
let target = parseInt(readline());
let arr = readline().split(' ').map(Number).sort((a, b) => a - b);

// find triplet
let found = false;
for(let i = 0; i < n - 2; i++) {
    let left = i + 1;
    let right = n - 1;
    while(left < right) {
        if(arr[i] + arr[left] + arr[right] == target) {
            found = true;
            break;
        }
        if(arr[i] + arr[left] + arr[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    if(found) break;
}

// output
console.log(found ? 'Yes' : 'No');