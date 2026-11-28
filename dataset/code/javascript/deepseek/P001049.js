Here is the JavaScript code for your problem.

process.stdin.resume();
process.stdin.on('data', function(chunk) {
    var input = chunk.toString().split('\n');
    var N = parseInt(input[0].split(' ')[0]);
    var arr = input[1].split(' ').map(Number);
    var Q = parseInt(input[2]);

    var operations = [];
    for (var i = 0; i < Q; i++) {
        var line = input[i + 3].split(' ');
        operations.push({
            index: parseInt(line[0]) - 1,
            newValue: parseInt(line[1])
        });
    }

    var heap = [];
    arr.forEach(function(num, i) {
        heap.push({ num: num, index: i });
    });

    heap.sort(function(a, b) {
        return a.num - b.num;
    });

    for (var i = 0; i < Q; i++) {
        var operation = operations[i];
        var newValue = operation.newValue;
        var index = operation.index;
        var oldValue = heap[index].num;

        heap[index].num = newValue;

        while (index > 0 && heap[index].num < heap[(index - 1) >> 1].num) {
            var parentIndex = (index - 1) >> 1;
            var temp = heap[index];
            heap[index] = heap[parentIndex];
            heap[parentIndex] = temp;

            index = parentIndex;
        }

        console.log(heap.map(function(node) { return node.num; }).join(' '));
    }
});

This program reads the input in the following way:

- The first line contains the number of elements N and the number of operations Q.
- The second line contains the elements of the binary heap.
- The next Q lines contain the index and new value of the operations.

It then processes the operations and prints the final binary heap after each operation.

The program uses a binary heap to keep the elements sorted in the binary heap. Each node in the heap is an object containing the element and its index in the original array. The heap property is maintained by ensuring that for any node, the element is greater than or equal to any of its children.

The operations are performed in the order they are given (the operations are given in the input). For each operation, the new value is replaced at the specified index, and the heap is re-adjusted to maintain the heap property. The final heap is printed at the end of each operation.