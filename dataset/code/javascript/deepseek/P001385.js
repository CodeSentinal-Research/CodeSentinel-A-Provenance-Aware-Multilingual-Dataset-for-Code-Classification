Here is a JavaScript solution for the problem:

process.stdin.setEncoding('utf8');

process.stdin.on('data', function(data) {
    const N = parseInt(data.split('\n')[0]);
    const arr = data.split('\n')[1].split(' ').map(Number);

    const missingNumbers = [];
    const totalNumbers = N + 1;

    for (let i = 1; i <= totalNumbers; i++) {
        if (!arr.includes(i)) {
            missingNumbers.push(i);
        }
    }

    missingNumbers.sort((a, b) => a - b);

    console.log(missingNumbers.join(' '));
});

In this code, we first read the first line of input, convert it to an integer. Then, we read the second line of input and split it into an array of integers. We then iterate over the range from 1 to N (inclusive), and if the current number is not found in the array, we add it to the missingNumbers array. Finally, we sort the missingNumbers array and print the sorted array.