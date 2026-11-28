function medianOfSubarray(arr, k) {
    let ws = arr.slice(0, k);
    let medians = [];

    // Sort the window
    ws.sort((a, b) => a - b);
    medians.push(ws[Math.floor(k / 2)]);

    if (k % 2 === 0) {
        medians.push(ws[k / 2 - 1]);
    }

    // Slide the window
    for (let i = k; i < arr.length; i++) {
        // Remove the left-out element
        const removed = ws.splice(ws.indexOf(arr[i - k]), 1);
        // Add the new element
        const pushed = ws.push(arr[i]);
        // Sort the window
        ws.sort((a, b) => a - b);
        // Push the median
        medians.push(ws[Math.floor(k / 2)]);
        if (k % 2 === 0) {
            medians.push(ws[k / 2 - 1]);
        }
    }

    return medians;
}

const input = [5, 2, 6, 1, 5, 2, 6, 1];
const k = 3;
console.log(medianOfSubarray(input, k));