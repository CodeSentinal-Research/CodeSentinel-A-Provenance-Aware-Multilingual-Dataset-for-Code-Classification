const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of strings: ', (N) => {
  let strings = [];
  rl.setPrompt('Enter a string: ');

  rl.prompt();

  for (let i = 0; i < N; i++) {
    strings.push(rl.line());
  }

  let set = new Set();
  let result = '';

  for (let string of strings) {
    for (let char of string) {
      if (!set.has(char)) {
        set.add(char);
        result += char;
      }
    }
  }

  console.log(result.length);

  rl.close();
});

This JavaScript code reads the number of strings from the standard input, then reads each string from the standard input. It then concatenates the characters of each string in a set and prints the length of the resulting string. The set ensures that each character in the string only appears once, hence maximizing the length of the concatenated string.