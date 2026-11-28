// 30. KADANE'S ALGORITHM PATTERNS - MAXIMUM SUBARRAY

/**
 * KADANE'S ALGORITHM - MAXIMUM SUBARRAY SUM PATTERN
 * 
 * DESCRIPTION:
 * Kadane's algorithm finds the contiguous subarray with the maximum sum in O(n) time.
 * It uses dynamic programming by maintaining the maximum sum ending at each position.
 * The key insight is that at each position, we choose between starting fresh or
 * extending the previous subarray.
 * 
 * WHEN TO USE:
 * - Finding optimal contiguous subarray problems
 * - Profit maximization with consecutive elements
 * - Signal processing and smoothing
 * - Stock trading with single transaction
 * - Maximum sum rectangle in 2D matrix
 * - Various optimization problems with contiguous elements
 * 
 * WHY IT WORKS:
 * - Optimal substructure: optimal solution contains optimal subproblems
 * - At each position, we make a greedy choice that's globally optimal
 * - Handles negative numbers by resetting when sum becomes negative
 * - Single pass through array makes it highly efficient
 * 
 * COMPLEXITY ANALYSIS:
 * - Time: O(n) - single pass through array
 * - Space: O(1) - only uses constant extra space
 * 
 * ALGORITHM MECHANICS:
 * 1. maxEndingHere: maximum sum of subarray ending at current position
 * 2. maxSoFar: maximum sum found so far (global maximum)
 * 3. At each step: extend current subarray or start new one
 * 
 * COMMON PROBLEM TYPES:
 * 1. Maximum Subarray Sum (Leetcode 53)
 * 2. Best Time to Buy and Sell Stock (Leetcode 121)
 * 3. Maximum Sum Circular Subarray (Leetcode 918)
 * 4. Maximum Product Subarray (variation)
 * 5. Largest Sum Contiguous Subarray
 * 6. Maximum Sum Rectangle in 2D Matrix
 * 7. Maximum Average Subarray
 * 8. Subarray with given sum
 */

// Basic Kadane's Algorithm
function maxSubArray(nums) {
    if (!nums || nums.length === 0) return 0;
    
    let maxSoFar = nums[0];        // Global maximum sum
    let maxEndingHere = nums[0];   // Maximum sum ending at current position
    
    for (let i = 1; i < nums.length; i++) {
        // Choice: start new subarray or extend previous one
        maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
        
        // Update global maximum
        maxSoFar = Math.max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

/**
 * KADANE'S ALGORITHM WITH POSITION TRACKING
 * Returns both maximum sum and the actual subarray
 */
function maxSubArrayWithIndices(nums) {
    if (!nums || nums.length === 0) return { sum: 0, start: -1, end: -1 };
    
    let maxSum = nums[0];
    let currentSum = nums[0];
    let start = 0, end = 0, tempStart = 0;
    
    for (let i = 1; i < nums.length; i++) {
        if (currentSum < 0) {
            currentSum = nums[i];
            tempStart = i;      // Potential new start
        } else {
            currentSum += nums[i];
        }
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;  // Update actual start
            end = i;           // Update end
        }
    }
    
    return {
        sum: maxSum,
        start: start,
        end: end,
        subarray: nums.slice(start, end + 1)
    };
}

/**
 * KADANE'S FOR ALL POSITIVE NUMBERS
 * When we want to handle edge case of all negative numbers
 */
function maxSubArrayAllowEmpty(nums) {
    if (!nums || nums.length === 0) return 0;
    
    let maxSum = 0;  // Allow empty subarray (sum = 0)
    let currentSum = 0;
    
    for (let num of nums) {
        currentSum = Math.max(0, currentSum + num);
        maxSum = Math.max(maxSum, currentSum);
    }
    
    return maxSum;
}

/**
 * MAXIMUM CIRCULAR SUBARRAY - Kadane's variation
 * Handles arrays where subarray can wrap around
 */
function maxCircularSubArray(nums) {
    if (!nums || nums.length === 0) return 0;
    
    // Case 1: Maximum subarray is non-circular (standard Kadane's)
    const normalMax = maxSubArray(nums);
    
    // Case 2: Maximum subarray is circular
    // Circular max = Total sum - Minimum subarray
    let totalSum = nums.reduce((sum, num) => sum + num, 0);
    
    // Find minimum subarray (invert signs and find maximum)
    let minSubarray = kadaneMin(nums);
    let circularMax = totalSum - minSubarray;
    
    // Handle edge case: all elements are negative
    if (circularMax === 0) return normalMax;
    
    return Math.max(normalMax, circularMax);
}

function kadaneMin(nums) {
    let minSoFar = nums[0];
    let minEndingHere = nums[0];
    
    for (let i = 1; i < nums.length; i++) {
        minEndingHere = Math.min(nums[i], minEndingHere + nums[i]);
        minSoFar = Math.min(minSoFar, minEndingHere);
    }
    
    return minSoFar;
}

/**
 * MAXIMUM SUBARRAY OF LENGTH K - Fixed size window
 */
function maxSubArrayOfLengthK(nums, k) {
    if (!nums || nums.length < k) return 0;
    
    // Calculate sum of first k elements
    let windowSum = 0;
    for (let i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    let maxSum = windowSum;
    
    // Slide the window
    for (let i = k; i < nums.length; i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        maxSum = Math.max(maxSum, windowSum);
    }
    
    return maxSum;
}

/**
 * STOCK TRADING - Single transaction using Kadane's
 */
function maxProfit(prices) {
    if (!prices || prices.length <= 1) return 0;
    
    let maxProfit = 0;
    let minPrice = prices[0];
    
    for (let i = 1; i < prices.length; i++) {
        // This is essentially Kadane's on price differences
        maxProfit = Math.max(maxProfit, prices[i] - minPrice);
        minPrice = Math.min(minPrice, prices[i]);
    }
    
    return maxProfit;
}

/**
 * 2D KADANE'S - Maximum sum rectangle in matrix
 */
function maxSumRectangle(matrix) {
    if (!matrix || matrix.length === 0) return 0;
    
    const rows = matrix.length;
    const cols = matrix[0].length;
    let maxSum = -Infinity;
    
    // Try all possible top and bottom row combinations
    for (let top = 0; top < rows; top++) {
        let temp = new Array(cols).fill(0);
        
        for (let bottom = top; bottom < rows; bottom++) {
            // Add current row to temp array
            for (let i = 0; i < cols; i++) {
                temp[i] += matrix[bottom][i];
            }
            
            // Apply Kadane's algorithm on temp array
            let currentMax = maxSubArray(temp);
            maxSum = Math.max(maxSum, currentMax);
        }
    }
    
    return maxSum;
}

/**
 * KADANE'S WITH DIVISION BY ZERO HANDLING
 * For average subarray problems
 */
function maxAverageSubArray(nums, k) {
    if (!nums || nums.length < k) return 0;
    
    let sum = 0;
    for (let i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    let maxSum = sum;
    
    for (let i = k; i < nums.length; i++) {
        sum = sum - nums[i - k] + nums[i];
        maxSum = Math.max(maxSum, sum);
    }
    
    return maxSum / k;
}

/**
 * EDGE CASES TO CONSIDER:
 * 1. Empty array
 * 2. Single element array
 * 3. All negative numbers
 * 4. All positive numbers
 * 5. Array with zeros
 * 6. Very large numbers (overflow)
 * 
 * VARIATIONS AND EXTENSIONS:
 * 1. Maximum Product Subarray (different algorithm needed)
 * 2. Minimum Subarray Sum (invert the logic)
 * 3. K-Kadane (maximum sum of k non-overlapping subarrays)
 * 4. Subarray with given sum
 * 5. Longest subarray with sum ≤ k
 * 6. Maximum average subarray
 * 
 * DEBUGGING TIPS:
 * 1. Trace through algorithm with small examples
 * 2. Check handling of negative numbers
 * 3. Verify edge cases (empty, single element)
 * 4. Ensure maxSoFar is properly updated
 * 5. Test with all negative array
 * 
 * OPTIMIZATION NOTES:
 * 1. Already optimal in time and space
 * 2. Can be parallelized for very large arrays
 * 3. Consider numerical stability for floating point
 * 4. Memory access patterns are cache-friendly
 * 
 * RELATED ALGORITHMS:
 * 1. Maximum Product Subarray (Kadane's variation)
 * 2. Sliding Window Maximum
 * 3. Best Time to Buy and Sell Stock
 * 4. Largest Rectangle in Histogram
 * 5. Trapping Rain Water
 */

export default maxSubArray;