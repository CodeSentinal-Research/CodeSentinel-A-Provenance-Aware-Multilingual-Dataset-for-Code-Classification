Here is the JavaScript code:

let readline = require('readline');

let input = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = Number(input.next());
let target = Number(input.next());
let arr = input.next().split(' ').map(Number);

function findPair(arr, target) {
    let map = {};
    for(let i = 0; i < arr.length; i++) {
        if(map[target - arr[i]]) {
            console.log('Yes');
            return;
        } else {
            map[arr[i]] = true;
        }
    }
    console.log('No');
}

findPair(arr, target);

This code uses a Hashmap data structure (an object in JavaScript) to store the difference between the target and the current element. If the difference is already in the Hashmap, then we have found a pair that sums up to the target. Otherwise, we put the current element into the Hashmap.

Please note that the readline module is used to get input from the console. If you want to use this in an online JavaScript environment, you can remove the require statement and use the input/output operations directly.