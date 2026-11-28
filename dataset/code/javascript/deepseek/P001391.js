Here is a JavaScript solution for the problem:

function subarraySum(arr, k) {
    let count = 0;
    let map = new Map();
    let sum = 0;

    // Initialize the sum of the first window
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];

        // If sum equals k, increment the count
        if (sum === k) {
            count++;
        }

        // If sum exceeds k or no more elements remain, decrement sum from left
        if (sum > k) {
            sum -= arr[i - (map.get(sum - k) || 0)];
        }

        // If sum is not present in map, then insert it
        if (!map.has(sum)) {
            map.set(sum, i);
        }
    }

    return count;
}

// Example usage:
let arr = [1, 1, 1, 1, 1];
let k = 2;
console.log(subarraySum(arr, k)); // 3

This code works by maintaining a running sum of the elements in the array and checking if the sum equals the target value k. If it does, it increments a counter. If the sum exceeds k, it subtracts the leftmost element and checks if the sum has been previously encountered in the map. If it has, it knows the leftmost index of the sum (its leftmost occurrence) and can calculate the rightmost occurrence by subtracting the sum from the leftmost index. The map is used to store the sum and its index, allowing for constant time lookup.