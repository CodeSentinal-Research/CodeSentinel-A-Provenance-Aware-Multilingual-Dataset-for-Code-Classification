Here is the JavaScript code for your problem. This code reads the input from the standard input and then calculates the original array using the formula for the resulting array.

process.stdin.setEncoding('utf-8');
process.stdin.on('data', function(input) {
    var lines = input.split('\n');
    var N = parseInt(lines[0]);
    var nums = lines[1].split(' ').map(Number);
    var sum = nums.reduce((a, b) => a + b, 0);
    var original = nums.map(num => num + sum - N);
    console.log(original.join(' '));
});

This code reads the first line of the input, which is the number of elements in the original array, and then reads the next line, which is a space-separated list of integers. It then calculates the sum of the original array elements and uses this sum to calculate the original array elements. Finally, it prints the original array elements.

Please note that this code assumes that the input follows the exact format you've provided. In practice, you'll want to handle errors and edge cases appropriately.