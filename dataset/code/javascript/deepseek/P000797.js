Here is the JavaScript code to solve the problem:

function countSubarrays(nums) {
    let count = 0;
    let zeroCount = 0;
    let oneCount = 0;

    for (let num of nums) {
        if (num === 0) {
            zeroCount = 0;
            oneCount = 0;
            zeroCount++;
        } else {
            oneCount++;
        }

        count += zeroCount + oneCount;
    }

    return count;
}

This function iterates through the input array and counts the number of 0s and 1s in each subarray. It then adds the count of 0s and 1s in the current subarray to the total count. This is done for all numbers in the array.