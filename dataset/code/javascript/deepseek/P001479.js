const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function(line) {
    input = line.split(' ').map(Number);
    rl.close();
}).on('close', function() {
    const findUnsorted = (arr) => {
        let start = -1, end = -1;
        let inversion = 0;
        for (let i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                if (start == -1)
                    start = i;
                end = i + 1;
                inversion++;
            }
        }
        if (inversion == 0)
            return 0;
        if (start == -1)
            return arr.length;

        let min = arr[start], max = arr[start];
        for (let i = start; i <= end; i++) {
            if (arr[i] < min)
                min = arr[i];
            if (arr[i] > max)
                max = arr[i];
        }

        for (let i = 0; i < start; i++) {
            if (arr[i] > min) {
                start = i;
                break;
            }
        }

        for (let i = arr.length - 1; i > end; i--) {
            if (arr[i] < max) {
                end = i;
                break;
            }
        }
        return end - start + 1;
    };

    console.log(findUnsorted(input));
});