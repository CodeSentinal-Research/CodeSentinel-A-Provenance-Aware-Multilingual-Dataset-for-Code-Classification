Here's a JavaScript solution using a stack to handle the input arrays:

function nextGreaterElement(nums1, nums2) {
    let map = new Map();
    let stack = [];
    for (let num of nums2) {
        while (stack.length && num > stack[stack.length - 1]) {
            let poppedNum = stack.pop();
            map.set(poppedNum, num);
        }
        stack.push(num);
    }
    return nums1.map(num => map.get(num) || -1).concat();
}

In this function, we iterate over nums2, and for each num in nums2, we continuously pop elements from the stack until we find a num that is smaller than num (which means there is a next greater element on the right). We then store the popped element as the next greater element for num. At the end, we map the nums1 to the corresponding next greater element from the map, and return the result.

The input handling is done via a for-of loop in JavaScript, where nums1 is a number array and nums2 is a list of numbers. The for-of loop iterates over the elements of nums1, and the loop iterates over nums2.