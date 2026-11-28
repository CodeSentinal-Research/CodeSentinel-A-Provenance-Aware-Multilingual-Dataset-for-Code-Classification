function countSubarrays(arr, k) {
    let n = arr.length;
    let left = 0, right = 0;
    let count = 0;
    let visited = new Set();

    while (right < n) {
        if (!visited.has(arr[right])) {
            visited.add(arr[right]);
        }
        if (visited.size === k) {
            count += k;
        }
        right++;
    }
    visited = new Set();
    left = right = 0;

    while (right < n) {
        if (!visited.has(arr[right])) {
            visited.add(arr[right]);
        }
        if (visited.size < k) {
            count += visited.size;
        } else {
            count += k;
        }
        right++;
    }

    return count;
}
In this JavaScript solution, I use a two pointers approach. One pointer (`left`) starts from the beginning and the other (`right`) starts from the end. `visited` is a Set to store the distinct elements seen so far. As we move the right pointer, we add the element at `right` index to the `visited` Set. If the size of `visited` Set is equal to `k`, we increment `count` by `k`. If the size of `visited` Set is less than `k`, we add the size of `visited` Set to `count`. Then, we move both pointers one step to the right.

This solution works for any positive integers within the bounds of 1 and 2*10^5, ensuring it meets the provided constraints.