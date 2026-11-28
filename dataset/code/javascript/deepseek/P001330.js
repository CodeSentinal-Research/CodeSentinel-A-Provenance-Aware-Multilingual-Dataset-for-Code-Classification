Here is the code in JavaScript:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter a string: ', (str) => {
  rl.close();
  partition(str);
});

function partition(str) {
  const result = [];
  const path = [];

  function isPalindrome(s) {
    const len = s.length;
    for (let i = 0; i < Math.floor(len / 2); i++) {
      if (s[i] !== s[len - 1 - i]) {
        return false;
      }
    }
    return true;
  }

  function backtrack(s, start) {
    if (start === s.length) {
      result.push(path.slice());
      return;
    }

    for (let i = start; i < s.length; i++) {
      if (isPalindrome(s.slice(start, i + 1))) {
        path.push(s.slice(start, i + 1));
        backtrack(s, i + 1);
        path.pop();
      }
    }
  }

  backtrack(str, 0);

  result.sort().forEach((partition) => {
    console.log(partition.join(''));
  });
}

This code first asks for user input and then calls the partition function. The partition function recursively generates all palindrome partitions using backtracking. It uses the `readline` module to handle user input.