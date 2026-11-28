const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of elements: ', (num) => {
  rl.question('Enter elements: ', (elements) => {
    const arr = elements.split(' ').map(Number);
    const sortedArr = arr.slice().sort((a, b) => a - b);
    let waveArr = [sortedArr[0]];
    for (let i = 1, len = sortedArr.length; i < len; i++) {
      if (i % 2 === 0) {
        waveArr.push(sortedArr[i + 1]);
      } else {
        waveArr.push(sortedArr[i - 1]);
      }
    }
    if (waveArr.length < arr.length) {
      waveArr.push(waveArr[0]);
    }
    console.log(waveArr.join(' '));
    rl.close();
  });
});
This JavaScript code will take an array of integers as input and sort it into wave form. The wave-form array is constructed by alternately taking the smaller and larger elements from the sorted array, starting with the first element of the sorted array. If the array length is odd, it will include the first element again at the end to make the wave form complete.