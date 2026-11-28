const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tests = [];

rl.on('line', (line) => {
  tests.push(line.split(' ').map(Number));
  if(tests.length == 2){
    rearrangeBarcodes(tests[0], tests[1]);
    tests = [];
  }
});

rl.on('close', () => {
  if(tests.length > 0){
    rearrangeBarcodes(tests[0], tests[1]);
  }
  process.exit();
});

function rearrangeBarcodes(N, barcodes) {
  let map = new Map();
  for(let barcode of barcodes){
    if(map.has(barcode)){
      map.set(barcode, map.get(barcode) + 1);
    }else{
      map.set(barcode, 1);
    }
  }
  let maxHeap = new MaxPriorityQueue();
  map.forEach((count, barcode) => {
    maxHeap.enqueue([barcode, count]);
  });
  let prevBarcode = maxHeap.dequeue().item;
  let prevCount = 0;
  let res = Array(N).fill(0);
  while(!maxHeap.isEmpty()){
    let currBarcode = maxHeap.dequeue().item;
    res[--N] = currBarcode[0];
    let nextCount = currBarcode[1];
    if(prevCount > 0){
      res[--N] = prevBarcode;
      prevCount--;
    }
    prevBarcode = currBarcode[0];
    prevCount = currBarcode[1];
    if(nextCount > 1){
      maxHeap.enqueue([currBarcode[0], nextCount - 1]);
    }
  }
  console.log(res.join(' '));
}

This JavaScript code reads the input and processes the test cases. It counts the occurrences of each barcode and puts them in a MaxPriorityQueue. The queue is used to dequeue the barcodes from the queue in the order of their count, and we fill the result array by this.