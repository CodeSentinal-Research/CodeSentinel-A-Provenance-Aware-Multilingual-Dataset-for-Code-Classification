Here is the JavaScript code:

function solveProblem() {
  let input = process.stdin;

  input.setEncoding('utf8');

  input.on('data', function(chunk) {
    let str = chunk.toString();
    let count = new Map();
    let maxCount = 0;
    let maxChar = null;

    for (let i = 0; i < str.length; i++) {
      let char = str.charAt(i);
      count.set(char, (count.get(char) || 0) + 1);
      if (maxCount < count.get(char)) {
        maxCount = count.get(char);
        maxChar = char;
      }
    }

    console.log(maxChar + ' ' + maxCount);
  });

  input.on('end', function() {
    console.log('Finished processing');
  });
}

solveProblem();

In this code, we are reading the input line by line, character by character. We keep track of the maximum count and the character that has the maximum count. If the current character's count is more than our maxCount, we update our maxCount and maxChar. After processing all characters, we print the maxChar and maxCount.