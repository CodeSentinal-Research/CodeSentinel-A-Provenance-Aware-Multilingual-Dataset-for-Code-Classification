Here is the JavaScript code:

process.stdin.resume();
process.stdin.on('data', function(data) {
    var input = data.toString().trim().split('\n');
    var N = parseInt(input[0]);
    var sum = parseInt(input[1]);
    var arr = input[2].split(' ').map(Number);

    var start = 0;
    var end = 0;
    var currentSum = 0;
    var flag = false;

    while (end < N) {
        while (currentSum < sum && end < N) {
            currentSum += arr[end];
            end++;
        }

        while (currentSum >= sum && start < end) {
            if (currentSum == sum) {
                flag = true;
                console.log('Starting index: ' + (start + 1) + ', Ending index: ' + (end - 1) + ', Sum: ' + sum);
                process.stdout.write('Starting index: ' + (start + 1) + ', Ending index: ' + (end - 1) + ', Sum: ' + sum + '\n');
            }
            currentSum -= arr[start];
            start++;
        }

        currentSum = 0;
    }

    if (!flag) {
        console.log(-1);
        process.stdout.write(-1 + '\n');
    }
});
This code reads the input as the first line is the size of the array, the second line is the target sum, and the remaining lines are the elements of the array. It then finds the continuous subarray that sums up to the given sum. If no such subarray exists, it prints -1.