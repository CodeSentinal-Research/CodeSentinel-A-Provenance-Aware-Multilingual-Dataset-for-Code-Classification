Here is the JavaScript code to solve the problem:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
    input = input.split('\n');
    var N = parseInt(input[0]);
    var arr = input[1].split(' ').map(Number);
    var replacement = parseInt(input[2]);
    var maxHeap = [];
    function siftUp(i) {
        if(i < 1) return;
        var p = Math.floor((i-1)/2);
        if(arr[p] < arr[i] && arr[p] < arr[i] && arr[p] < arr[i]) {
            var temp = arr[p];
            arr[p] = arr[i];
            arr[i] = temp;
            siftUp(p);
        }
    }
    function siftDown(i) {
        var l = 2*i + 1;
        var r = 2*i + 2;
        var largest = i;
        if(l < N && arr[l] > arr[largest]) largest = l;
        if(r < N && arr[r] > arr[largest]) largest = r;
        if(largest != i) {
            var temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            siftDown(largest);
        }
    }
    for(var i = 0; i < N; i++) {
        maxHeap.push(arr[i]);
    }
    maxHeap.sort(function(a, b) {
        return b-a;
    });
    maxHeap[0] = replacement;
    siftDown(0);
    siftUp(0);
    console.log(maxHeap.join(' '));
});

This code reads an array and a replacement value from standard input, creates a max heap from the array, replaces the root of the heap with the replacement value, and then restores the heap property by sifting down and up the root. The resulting heap is printed to standard output. The maxHeap variable is a max heap represented as an array, and the siftUp and siftDown functions are used to maintain the heap property. The siftUp function is used to sift up the newly inserted node, and the siftDown function is used to sift down the newly inserted node.