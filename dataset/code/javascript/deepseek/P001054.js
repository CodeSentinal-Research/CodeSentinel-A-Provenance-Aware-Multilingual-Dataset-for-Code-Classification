Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases = process.argv[2];
rl.question('Enter the number of test cases:', (testCases) => {
  while(testCases--) {
    rl.question('Enter the size of the array:', (size) => {
      rl.question('Enter the elements of the array:', (arr1) => {
        rl.question('Enter the elements of the array:', (arr2) => {
          const pairs = [];
          const minHeap = new MinHeap();

          // Pair the elements of the arrays and add to minHeap
          for(let i = 0; i < arr1.length; i++) {
            for(let j = 0; j < arr2.length; j++) {
              minHeap.push(arr1[i] + arr2[j]);
              if(minHeap.size() > size) {
                minHeap.pop();
              }
            }
          }

          // Print the k largest pair sums
          while(minHeap.size() > size) {
            minHeap.pop();
          }

          while(!minHeap.isEmpty()) {
            pairs.push(minHeap.pop());
          }

          console.log('K largest pair sums:', pairs);
        });
      });
    });
  }
  rl.close();
});
In this code, we use a min heap to store the pair sums of the two arrays. The pair sum of two elements is calculated by adding them together. We then store these pair sums in the min heap and keep removing the smallest pair sum until the heap size is equal to k. Finally, we print the k largest pair sums.

Please note that the `readline` module is used to read the input from the standard input. The `MinHeap` is a simple implementation of a min heap. The `MinHeap` class includes methods for pushing a new value, popping the minimum value, checking if the heap is empty, and getting the size of the heap.