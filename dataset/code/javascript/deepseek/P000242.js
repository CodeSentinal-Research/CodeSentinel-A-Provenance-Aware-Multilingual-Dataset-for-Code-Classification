Here is the JavaScript code for your problem:

// Read the number of rows from standard input
let N = parseInt(process.stdin.read());

// Create an empty array to store the matrix
let matrix = [];

// Read the matrix from standard input
for (let i = 0; i < N; i++) {
    matrix[i] = process.stdin.readline().toString().trim().split(' ').map(Number);
    matrix[i].sort((a, b) => a - b); // Sort the row
}

// Count the zeros
let zeros = 0;

for (let i = 0; i < N; i++) {
    let row = matrix[i];
    let left = 0;
    let right = row.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (row[mid] === 0) {
            zeros += mid;
            break;
        } else if (row[mid] < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

// Write the number of zeros to standard output
process.stdout.write(zeros.toString() + '\n');

In this code, we first read the number of rows N from standard input. We then create a matrix where each row is sorted. We count the zeros in the matrix by iterating over each row and using binary search to find the first occurrence of the zero. If the zero is found, we add the index to the count. Finally, we write the count to standard output.

Please note that this code assumes that the input matrix is a square matrix, where each row is sorted.