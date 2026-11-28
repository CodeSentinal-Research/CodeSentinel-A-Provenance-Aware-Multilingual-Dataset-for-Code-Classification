Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let V;
rl.once('line', (line) => {
  V = parseInt(line);
  let votes = new Array(V).fill(0).map(() => new Array(26).fill(0));
  let letters = new Array(26).fill(0).map((_, i) => String.fromCharCode(65 + i));
  let maxLetter = '';
  let maxVotes = 0;

  rl.once('line', (line) => {
    let vote = new Array(V).fill(0).map((_, i) => line[i]);
    votes[i] = vote;
    for (let j = 0; j < 26; j++) {
      if (votes[i][j] > maxVotes) {
        maxVotes = votes[i][j];
        maxLetter = letters[j];
      } else if (votes[i][j] === maxVotes) {
        maxLetter = maxLetter < letters[j] ? maxLetter : letters[j];
      }
    }
    console.log(maxLetter);
  });

  rl.close();
});
This code first reads the number of voters V. Then, for each voter, it reads a string of votes. The votes are converted to a two-dimensional array where each row represents a voter and each column represents a letter of the alphabet. The number of votes for each letter is then counted and the letter with the most votes is printed. If there is a tie, it prints the lexicographically smallest letter.