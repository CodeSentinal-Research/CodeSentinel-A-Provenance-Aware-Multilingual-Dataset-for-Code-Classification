Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let equations = new Map();

rl.on('line', (line) => {
  let [a, b, res] = line.split(' ');
  equations.set(a, equations.get(a) ? equations.get(a) / b : res);

  if (equations.get(b)) {
    equations.set(a, equations.get(a) / equations.get(b));
  } else {
    equations.set(a, -1.0);
  }
});

rl.on('line', (line) => {
  let [a, b] = line.split(' ');
  if (equations.get(a) || equations.get(b)) {
    let aRes = equations.get(a);
    let bRes = equations.get(b);

    if (aRes === undefined || bRes === undefined) {
      console.log(-1.0);
    } else {
      console.log(aRes === bRes ? aRes : -1.0);
    }
  } else {
    console.log(-1.0);
  }
});

rl.on('close', () => {
  process.exit(0);
});

In this code, we use the `readline` module to read the inputs in the stream. We set up two readlines. One for the equation inputs and the other for the queries. 

The first readline reads the equations and stores them in a Map with the equation variable as the key and the equation value as the value. We also set up a check to see if the value for the variable is undefined when the second readline is run. If it is, we print -1.0.

The second readline is used for the queries. If the result for both variables is not defined, we print -1.0. If it is, we print the result.

This code assumes that there are no floating point errors when dividing, and that the input does not contain any unexpected characters.