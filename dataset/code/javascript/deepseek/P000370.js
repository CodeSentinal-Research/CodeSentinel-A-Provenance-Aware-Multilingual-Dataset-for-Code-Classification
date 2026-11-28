function searchDuplicateValue(n, arr) {
    // Create an empty object to store array values and their counts
    let counts = {};

    // Loop through the array
    for (let i = 0; i < n; i++) {
        // If the current array value is not in counts, add it and set the count to 1
        if (!counts[arr[i]]) {
            counts[arr[i]] = 1;
        } 
        // If the current array value is already in counts, it's a duplicate and return it
        else {
            return arr[i];
        }
    }

    // If no duplicates exist, return -1
    return -1;
}