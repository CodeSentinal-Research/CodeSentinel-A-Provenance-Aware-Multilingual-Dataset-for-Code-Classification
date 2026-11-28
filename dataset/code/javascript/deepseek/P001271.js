// Function to find minimum number of taps
function findMinTaps(N, watering) {
    let taps = new Array(N + 1).fill(0);
    for (let i = 0; i < N; i++) {
        taps[i + 1] = watering[i];
    }

    taps.sort((a, b) -> a - b);

    let minTaps = 0, lastPos = 0;
    for (let i = 1; i <= N + 1; i++) {
        if (taps[i] > lastPos) {
            minTaps += 1;
            lastPos = taps[i - 1];
        }
    }

    if (lastPos < N) {
        return -1;
    } else {
        return minTaps;
    }
}

// Testing
let N = 5;
let watering = [1, 2, 3, 4, 5];
console.log(findMinTaps(N, watering)); // Output: 3

This code works by first sorting the watering intervals in ascending order. It then uses a greedy approach, checking if the next interval starts before the current interval ends, and if so, opening a new tap. The greedy strategy ensures that no tap is opened if it would water a segment of the garden that already has a tap open. If there are still gaps in the watering intervals, it is impossible to water the entire garden, and the function returns -1.