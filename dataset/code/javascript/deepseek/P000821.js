Here is the JavaScript code using bitwise XOR operation to find the single element in the sorted array:

function singleNonDuplicate(nums) {
    let result = 0;
    for (let num of nums) {
        result ^= num;
    }
    return result;
}

This solution works by using XOR operation which is a bitwise operation where only one of the two bits needs to be set in order for the result to be set. XOR of a number with itself results in 0, and XOR of a number with 0 results in the number itself. So in the end we end up with the single element in the array.

However, note that the above solution assumes that the input array is sorted in ascending order. If the input array is not sorted, we need to sort it first before applying this solution.

Also, note that the time complexity of this solution is O(n), where n is the number of elements in the array. This is because we have to traverse through each element in the array once. The space complexity is O(1), because no additional space is used, regardless of the size of the input.