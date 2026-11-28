const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        const arr = input.slice(1, n + 1).map(Number);
        let low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] === 0) {
                [arr[low], arr[mid]] = [arr[mid], arr[low]];
                low++; mid++;
            } else if (arr[mid] === 1) {
                mid++;
            } else {
                [arr[mid], arr[high]] = [arr[high], arr[mid]];
                high--;
            }
        }
        console.log(arr.join(' '));
    }
}
main();