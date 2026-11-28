Here's the JavaScript code for the problem:

function trapRainWater(heights) {
    if (heights.length === 0) {
        return 0;
    }
    let left = 0;
    let right = heights.length - 1;
    let maxLeft = heights[left];
    let maxRight = heights[right];
    let total = 0;
    while (left < right) {
        if maxLeft < maxRight {
            left++;
            if (heights[left] > maxLeft) {
                total += (maxLeft - heights[left]);
            } else {
                maxLeft = heights[left];
            }
        } else {
            right--;
            if (heights[right] > maxRight) {
                total += (maxRight - heights[right]);
            } else {
                maxRight = heights[right];
            }
        }
    }
    return total;
}

The code first checks if the array is empty, if it is then it returns 0. Then it initializes left and right pointers to the first and last element of the array, and maxLeft and maxRight as the max height of the left and right side of the array.

Then it enters a while loop which continues until the left pointer is less than the right pointer. Inside the loop, it checks if maxLeft is less than maxRight and if it is, it increments the left pointer. If the height at the left pointer is greater than maxLeft, it adds the difference to the total. If not, it updates maxLeft. If maxLeft is greater than the height at the left pointer, it updates maxLeft.

If maxLeft is greater than maxRight, it does the same as above, but it decrements the right pointer. If maxRight is greater than the height at the right pointer, it updates maxRight.

Finally, it returns the total amount of water that can be trapped.