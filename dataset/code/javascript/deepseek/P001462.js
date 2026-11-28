const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter the elements: ', (elements) => {
    const arr = elements.split(' ').map(Number);
    const result = removeDuplicates(arr);
    console.log(result.length, result.join(' '));
    rl.close();
  });
});

function removeDuplicates(arr) {
  let i = 0;
  for (let j = 1; j < arr.length; j++) {
    if (arr[i] !== arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return arr.slice(0, i + 1);
}
In the above code, we are using the readline module from node.js which allows us to read from the console in an interactive way. We are reading the number of elements and the elements themselves from the console. We are then passing these inputs to a function removeDuplicates which will return the new length and the new array.