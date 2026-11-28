const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let heap = [];

rl.question('Enter number of elements: ', (num) => {
    rl.question('Enter elements: ', (elems) => {
        let inputs = elems.split(' ').map(Number);
        heap = inputs.map((num, i) => {
            return {
                num: num,
                idx: i
            }
        });
        rl.question('Enter index and new value: ', (query) => {
            let [i, newValue] = query.split(' ').map(Number);
            if (i >= 0 && i < num && newValue <= heap[i].num) {
                console.log('Given new value is smaller than current value, cannot update key.');
                console.log('Updated heap:', heap);
                return;
            }
            heap[i].num = newValue;
            siftDown(i);
            console.log('Updated heap:', heap);
        });
        rl.close();
    });
});

function siftDown(i) {
    while (i * 2 + 1 < heap.length) {
        let left = heap[i * 2 + 1];
        let right = i * 2 + 2 < heap.length ? heap[i * 2 + 2] : Infinity;
        if (left.num <= right.num && heap[i].num > left.num) {
            swap(i, i * 2 + 1);
            i = i * 2 + 1;
        } else if (heap[i].num > right.num) {
            swap(i, i * 2 + 2);
            i = i * 2 + 2;
        } else {
            break;
        }
    }
}

function swap(i, j) {
    let temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}