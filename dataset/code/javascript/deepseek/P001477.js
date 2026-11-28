Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let firstString = '';
rl.question('Enter first string: ', (string) => {
  firstString = string;
  rl.question('Enter second string: ', (string) => {
    let secondString = string;
    processString(firstString, secondString);
  });
});

function processString(s1, s2) {
  let stack1 = [];
  let stack2 = [];

  for (let i = 0; i < s1.length; i++) {
    if (s1[i] === '#') {
      if (stack1.length) {
        stack1.pop();
      }
    } else {
      stack1.push(s1[i]);
    }
  }

  for (let i = 0; i < s2.length; i++) {
    if (s2[i] === '#') {
      if (stack2.length) {
        stack2.pop();
      }
    } else {
      stack2.push(s2[i]);
    }
  }

  const result1 = stack1.join('');
  const result2 = stack2.join('');

  if (result1 === result2) {
    console.log('YES');
  } else {
    console.log('NO');
  }

  rl.close();
}

This code takes two strings as input from the user, processes them by removing all the backspaces and then compares the processed strings. It then prints 'YES' if the processed strings are equal, and 'NO' otherwise.