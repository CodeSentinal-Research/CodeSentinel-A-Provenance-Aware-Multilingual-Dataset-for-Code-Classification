function inversionCount(arr, n) {
    // Sorts the input array into ordered sequence.
    function mergeSort(l, r) {
        if (l >= r) return 0;
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((l + r) / 2);
        let inv = mergeSort(l, mid) + mergeSort(mid + 1, r);

        const temp = [];
        let i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push(arr[i++]);
            } else {
                temp.push(arr[j++]);
                inv += (mid - i + 1);
            }
        }

        while (i <= mid) temp.push(arr[i++]);
        while (j <= r) temp.push(arr[j++]);

        for (let k = 0; k < temp.length; k++) {
            arr[l + k] = temp[k];
        }

        return inv;
    }

    return mergeSort(0, n - 1);
}

module.exports = { inversionCount };