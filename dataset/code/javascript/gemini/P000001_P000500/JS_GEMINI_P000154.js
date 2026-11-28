function findTwoElement(arr) {
    const n = arr.length;
    let repeating = -1, missing = -1;

    for (let i = 0; i < n; i++) {
        const val = Math.abs(arr[i]);
        if (arr[val - 1] < 0) {
            repeating = val;
        } else {
            arr[val - 1] = -arr[val - 1];
        }
    }

    for (let i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }
    return [repeating, missing];
}

module.exports = { findTwoElement };