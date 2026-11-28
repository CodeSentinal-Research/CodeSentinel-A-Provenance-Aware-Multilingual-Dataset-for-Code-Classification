// ============================================================
// PROBLEM: Largest / Smallest / 2nd Largest / 2nd Smallest in Array
// ============================================================
//
// DEFINITION:
//   Given an array of numbers, find its maximum, minimum, second maximum,
//   and second minimum values in a single pass wherever possible.
//
// ============================================================
// APPROACH 1: Find Largest Element (Linear Scan)
// ============================================================
// HOW IT WORKS:
//   Step 1 → Initialize `max = -Infinity` (so any real number beats it).
//   Step 2 → Loop through every element in the array.
//   Step 3 → If the current element > max, update max.
//   Step 4 → Return max after the loop.
//
// TIME COMPLEXITY : O(n) — every element is visited exactly once.
// SPACE COMPLEXITY: O(1) — only one extra variable `max` is used.
//
// WHY O(n)?
//   We must look at all n elements at least once because the largest
//   could be at any position. There is no shortcut that avoids this.

const largestElement = (values) => {
    let max = -Infinity
    for (const num of values) {
        if (num > max) {
            max = num
        }
    }
    return max
}

// ============================================================
// APPROACH 2: Find Smallest Element (Linear Scan)
// ============================================================
// HOW IT WORKS:
//   Step 1 → Initialize `min = +Infinity` (so any real number beats it).
//   Step 2 → Loop through every element in the array.
//   Step 3 → If the current element < min, update min.
//   Step 4 → Return min after the loop.
//
// TIME COMPLEXITY : O(n) — visits every element once.
// SPACE COMPLEXITY: O(1) — only one extra variable `min`.
//
// WHY O(n)?
//   Same reasoning as largestElement — we must scan the entire array.

const smallestElement = (values) => {
    let min = +Infinity
    for (const num of values) {
        if (num < min) {
            min = num
        }
    }
    return min
}

// ============================================================
// APPROACH 3: Find Second Largest Element (Single Pass, Two Variables)
// ============================================================
// HOW IT WORKS:
//   Step 1 → Initialize both `max` and `secondMax` to -Infinity.
//   Step 2 → For each element:
//              Case A: num > max  → secondMax becomes old max; max becomes num.
//              Case B: num > secondMax && num !== max → update secondMax only.
//   Step 3 → Return secondMax.
//
// TIME COMPLEXITY : O(n) — single pass through the array.
// SPACE COMPLEXITY: O(1) — only two extra variables.
//
// WHY O(n) and not O(n log n)?
//   A naive approach would sort the array (O(n log n)) and pick index [n-2].
//   But by tracking both max and secondMax simultaneously in one loop,
//   we reduce it to a single O(n) pass — no sorting needed.
//
// KEY INSIGHT:
//   The `num !== max` guard prevents equal values from being counted as distinct.
//   e.g., [5, 5, 3] → second largest is 3, not 5 again.

const secondLargestElement = (values) => {
    let max = -Infinity
    let secondMax = -Infinity
    for (const num of values) {``
        if (num > max) {
            secondMax = max
            max = num
        }
        else if (num > secondMax && num !== max) {
            secondMax = num
        }
    }
    return secondMax
}

// ============================================================
// APPROACH 4: Find Second Smallest Element (Single Pass, Two Variables)
// ============================================================
// HOW IT WORKS:
//   Step 1 → Initialize both `min` and `secondMin` to +Infinity.
//   Step 2 → For each element:
//              Case A: num < min  → secondMin becomes old min; min becomes num.
//              Case B: num < secondMin && num !== min → update secondMin only.
//   Step 3 → Return secondMin.
//
// TIME COMPLEXITY : O(n) — single pass through the array.
// SPACE COMPLEXITY: O(1) — only two extra variables.
//
// WHY O(n)?
//   Mirror logic of secondLargestElement. We avoid sorting by maintaining
//   two tracking variables simultaneously in one loop.

const secondSmallestElement = (values) => {
    let min = +Infinity
    let secondMin = +Infinity
    for (const num of values) {
        if (num < min) {
            secondMin = min
            min = num
        }
        else if (num < secondMin && num !== min) {
            secondMin = num
        }
    }
    return secondMin
}

console.log(largestElement([10, 20, 13, 46, 87, 26, 90, 92, 99]), smallestElement([5, 10, 20, 13, 46, 87, 26, 90, 92, 99]),
    secondLargestElement([10, 20, 13, 46, 87, 26, 90, 92, 99, 89]), secondSmallestElement([5, 10, 20, 13, 46, 87, 26, 90, 92, 99]))

// ============================================================
// EDGE CASES:
// ============================================================
// 1. Empty array []            → returns -Infinity (largest) / +Infinity (smallest)
// 2. Single element [5]        → secondLargest & secondSmallest return -Infinity / +Infinity
// 3. All same [3, 3, 3]        → secondLargest and secondSmallest return -Infinity / +Infinity
// 4. Negative numbers [-5,-2]  → works correctly since -Infinity/-+Infinity are baselines
// 5. Two distinct elements     → works correctly
