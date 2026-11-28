process.stdin.resume();
process.stdin.on('data', function(data){
    var n = parseInt(data);
    var nums = [];
    while (n-- > 0) {
        nums.push(parseInt(process.stdin.read()));
    }

    var counter = {};
    var pairs = 0;
    for (var i in nums) {
        if (counter[nums[i]]) {
            pairs += counter[nums[i]];
            counter[nums[i]]++;
        } else {
            counter[nums[i]] = 1;
        }
    }

    process.stdout.write(pairs + '\n');
    process.stdin.pause();
});