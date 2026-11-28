Here is the JavaScript code to solve the problem:

process.stdin.on('data', function(data) {
    var input = data.toString().trim();
    var whiteBalls = 0;
    var totalSwaps = 0;
    for (var i = 0; i < input.length; i++) {
        if (input[i] === '1') {
            if (i > 0 && input[i - 1] === '1') {
                whiteBalls++;
            } else {
                whiteBalls = 1;
            }
        } else {
            if (i > 0 && input[i - 1] === '0') {
                totalSwaps += whiteBalls;
                whiteBalls = 0;
            }
        }
    }
    totalSwaps += whiteBalls;
    console.log(totalSwaps);
});
This code reads the binary string from stdin, counts the number of white balls and the total number of swaps. If a white ball is encountered, it increases the count of white balls. If a black ball is encountered, it calculates the number of swaps required and updates the count of white balls. The total number of swaps is then printed to stdout.