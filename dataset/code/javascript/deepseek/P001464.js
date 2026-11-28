Here is the JavaScript code to solve the given problem:

// Input handling
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
    var arr = input.split(' ').map(Number);
    var N = arr[0];
    var nums = arr.slice(1);

    // Function to move zeros to end
    function moveZerosToEnd(nums, N) {
        var nonZero = 0;
        for (var i = 0; i < N; i++) {
            if (nums[i] != 0) {
                nums[nonZero] = nums[i];
                nonZero++;
            }
        }
        while (nonZero < N) {
            nums[nonZero] = 0;
            nonZero++;
        }
        return nums;
    }

    var result = moveZerosToEnd(nums, N);
    console.log(result.join(' '));
});

This code reads the input data, which is an array of integers, and then processes it. The function `moveZerosToEnd` moves all non-zero elements to the beginning of the array while preserving the order of the non-zero elements. The result is printed to the console.

Please note that this code assumes a Unix-like environment where process.stdin is available. If you're using Windows, you may need to adjust the code accordingly.