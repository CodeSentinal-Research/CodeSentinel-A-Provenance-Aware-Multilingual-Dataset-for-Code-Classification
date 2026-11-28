function rearrange(arr) {
    const n = arr.length;
    let maxIdx = n - 1, minIdx = 0;
    const maxElem = arr[n - 1] + 1;

    for (let i = 0; i < n; i++) {
        if (i % 2 === 0) {
            arr[i] += (arr[maxIdx] % maxElem) * maxElem;
            maxIdx--;
        } else {
            arr[i] += (arr[minIdx] % maxElem) * maxElem;
            minIdx++;
        }
    }

    for (let i = 0; i < n; i++) {
        arr[i] = Math.floor(arr[i] / maxElem);
    }
}

module.exports = { rearrange };