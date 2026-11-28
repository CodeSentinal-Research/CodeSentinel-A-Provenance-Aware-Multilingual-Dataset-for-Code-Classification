function printFloydTriangle(N) {
    if (N < 1 || N > 15) {
        console.log('Invalid input. Please enter a positive integer between 1 and 15.');
        return;
    }
    
    for (let i = 1; i <= N; i++) {
        let num = 1;
        for (let j = 1; j <= i; j++) {
            console.log(num, ' ');
            num++;
        }
        console.log();
    }
}
This JavaScript function `printFloydTriangle(N)` will print Floyd's triangle with N rows. The `for` loop in the outer loop iterates from 1 to N. The inner loop prints the numbers from 1 to `i` and then it increments the number by 1. This is done to create the actual Floyd's triangle.