// Input: N followed by array elements
let input = require('fs').readFileSync('stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let nums = input.split('\n')[1].split(' ').map(Number);

// Find if there exist two distinct indices i and j such that nums[i] = 2 * nums[j]
let found = false;
for (let i = 0; i < N; i++) {
    for (let j = i + 1; j < N; j++) {
        if (nums[i] === 2 * nums[j]) {
            console.log('YES');
            found = true;
            break;
        }
    }
    if (found) break;
}

if (!found) console.log('NO');
This JavaScript code reads the number N and the array elements from standard input. It then iterates over the array, checking for any two elements that are equal to twice the value of the other element. If such a pair is found, it prints "YES" and breaks the loop. If no such pair is found, it prints "NO".