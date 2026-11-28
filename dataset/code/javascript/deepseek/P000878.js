Here is the JavaScript code for the given problem. This code uses a technique called sliding window to find all possible contiguous subarrays. In the process, it uses a bitwise OR operation to obtain the bitwise OR of each subarray.

function subarraysBitwiseORs(nums) {
    if (!nums || nums.length === 0) {
        return 0;
    }
    
    let res = 0;
    let orSet = new Set();
    
    for (let i = 0; i < nums.length; i++) {
        let or = 0;
        let set = new Set();
        
        for (let j = i; j < nums.length; j++) {
            or = or | nums[j];
            
            if (!set.has(or)) {
                res++;
                set.add(or);
            }
        }
    }
    
    return res;
}

This code starts by checking if the input array is empty or null. If it is, the function returns 0. 

Then, it initializes a counter `res` to 0 and an empty `Set` `orSet` to store the bitwise OR values.

For each index `i` in the array, it starts a nested loop to find all possible contiguous subarrays from `i` to the end of the array. For each subarray, it calculates the bitwise OR using the bitwise OR operation and adds the result to the `orSet` if it hasn't been added before.

Finally, it returns the count of unique bitwise OR values.