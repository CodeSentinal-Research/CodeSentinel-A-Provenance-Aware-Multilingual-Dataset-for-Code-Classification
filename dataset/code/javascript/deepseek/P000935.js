Here is the JavaScript code to solve the problem:

function diagonalSum(N, A) {
    // Declare a variable to store the diagonal sum
    let sum = 0;
    
    // Loop through the matrix
    for(let i = 0; i < N; i++) {
        // Calculate the sum of main diagonal
        sum += A[i][i];
        
        // Calculate the sum of secondary diagonal
        sum += A[i][N-i-1];
    }
    
    // Return the diagonal sum
    return sum;
}

This function takes two parameters: the size of the matrix N and the matrix A. It then loops through each element in the matrix, adding the value to a sum variable. The sum is then returned.