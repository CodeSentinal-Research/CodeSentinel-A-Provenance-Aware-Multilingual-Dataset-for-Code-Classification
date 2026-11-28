process.stdin.setEncoding('utf-8');

process.stdin.on('data', function(data) {
    var [N, list1, M, list2] = data.split('\n').map(s => s.trim());
    N = parseInt(N);
    list1 = list1.split(' ');
    M = parseInt(M);
    list2 = list2.split(' ');

    // Assuming list1 and list2 are sorted
    var minIndexSum = Number.MAX_SAFE_INTEGER;
    var minStrings = [];
    var map = {};

    // First list
    for (var i = 0; i < N; i++) {
        var string = list1[i];
        var indexSum = getIndexSum(string, list2, map);
        if (indexSum < minIndexSum) {
            minIndexSum = indexSum;
            minStrings = [string];
        } else if (indexSum === minIndexSum) {
            minStrings.push(string);
        }
    }

    // Second list
    for (i = 0; i < M; i++) {
        var string = list2[i];
        var indexSum = getIndexSum(string, list1, map);
        if (indexSum < minIndexSum) {
            minIndexSum = indexSum;
            minStrings = [string];
        } else if (indexSum === minIndexSum) {
            minStrings.push(string);
        }
    }

    minStrings.sort();
    console.log(minStrings.join(' '));
});

function getIndexSum(string, list, map) {
    var sum = 0;
    for (var i = 0; i < string.length; i++) {
        if (!map[string[i]]) {
            map[string[i]] = true;
            sum += i;
        }
    }
    return sum;
}