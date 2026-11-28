Here is the JavaScript code that reads the input, counts the prefixes with a sum greater than zero, and then prints the count:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input){
    var lines = input.split('\n');
    var N = parseInt(lines[0]);
    var arr = lines[1].split(' ').map(Number);
    var prefixSums = [arr[0]];
    for(var i=1; i<arr.length; i++){
        prefixSums[i] = prefixSums[i-1] + arr[i];
    }
    var count = 0;
    for(var i=0; i<prefixSums.length; i++){
        if(prefixSums[i] > 0){
            count++;
        }
    }
    process.stdout.write(count + '\n');
});

In this code, we first read the number of integers `N` from the first line of input. Then we read the integers themselves, convert them to numbers, and store them in an array. We also create a new array `prefixSums` to store the prefix sums of the integers.

Next, we iterate through the `prefixSums` array and count the number of times the current sum is greater than zero.

Finally, we print the count of prefixes that have a sum greater than zero.