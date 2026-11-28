process.stdin.resume();
process.stdin.on('data', function(data){
    var N = parseInt(data.split(' ')[0]);
    var K = parseInt(data.split(' ')[1]);
    var arr = data.split(' ').slice(2).map(Number);

    function partition(arr, left, right) {
        var pivot = arr[right];
        var i = left;
        for (var j = left; j < right; j++) {
            if (arr[j] > pivot) {
                [arr[i], arr[j]] = [arr[j], arr[i]];
                i++;
            }
        }
        [arr[i], arr[right]] = [arr[right], arr[i]];
        return i;
    }

    function quickSelect(arr, left, right, k) {
        if (left === right) {
            return arr[left];
        }
        var pivotIndex = partition(arr, left, right);
        if (k === pivotIndex) {
            return arr[k];
        } else if (k < pivotIndex) {
            return quickSelect(arr, left, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, right, k);
        }
    }

    console.log(quickSelect(arr, 0, N - 1, K - 1));
});
This JavaScript code uses a variant of the quicksort algorithm to find the Kth largest element in the array. The partition function rearranges the array so that all elements with values less than the pivot come before the pivot, and all elements with values greater come after it. The quickSelect function then recursively applies this partitioning process to the appropriate partition of the array for each recursive call.

The input is read from standard input, and the output is written to standard output. The input is expected to be a single line of space-separated integers, where the first integer is the number of integers (N), and the second integer is the Kth largest element (K).