function findPeak(arr) {
    let left = 0;
    let right = arr.length - 1;

    while (left < right) {
        const mid = Math.floor((left + right) / 2);

        if (arr[mid] > arr[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

function solve() {
    const [n, ...arr] = readline().split(' ').map(Number);

    for (let i = 0; i < n; i++) {
        if (i > 0 && arr[i] > arr[i - 1]) {
            console.log(i);
            return;
        }
    }

    console.log(-1);
}

function readline() {
    return process.stdin.readline();
}