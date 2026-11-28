Sure, here is a simple JavaScript solution using the merge sort algorithm.

function mergeSort(nums) {
    if (nums.length <= 1) {
        return nums;
    }

    const mid = Math.floor(nums.length / 2);
    const left = nums.slice(0, mid);
    const right = nums.slice(mid);

    return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
    const result = [];
    let i = 0, j = 0;

    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
            result.push(left[i]);
            i++;
        } else {
            result.push(right[j]);
            j++;
       
        }
    }

    while (i < left.length) {
        result.push(left[i]);
        i++;
    }

    while (j < right.length) {
        result.push(right[j]);
        j++;
    }

    return result;
}

// Test the function
console.log(mergeSort([38, 27, 43, 3, 9, 82, 10]));  // Outputs: [3, 9, 10, 27, 38, 43, 82]

The `mergeSort` function splits the array into two halves and recursively sorts them. The `merge` function merges two sorted arrays into one sorted array.