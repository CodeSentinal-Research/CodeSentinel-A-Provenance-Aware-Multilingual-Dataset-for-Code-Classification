let [N, power] = process.argv[2].split(' ').map(Number);
let tokens = process.argv[3].split(' ').map(Number);

let tokensSet = new Set(tokens);
let tokensArr = Array.from(tokensSet);

let scores = new Array(N).fill(1);

let maxScore = 0;
let left = 0;
let right = N - 1;

while (left <= right) {
  if (power >= tokensArr[left]) {
    let score = tokensArr[left];
    power -= score;
    maxScore += score;
    while (left < right && power >= tokensArr[right]) {
      right--;
      score += tokensArr[right];
      power -= tokensArr[right];
      maxScore = Math.max(maxScore, score);
    }
    left++;
  } else if (power >= tokensArr[right]) {
    let score = tokensArr[right];
    power -= score;
    maxScore += score;
    while (left < right && power >= tokensArr[left]) {
      left++;
      score += tokensArr[left];
      power -= tokensArr[left];
      maxScore = Math.max(maxScore, score);
    }
    right--;
  } else {
    break;
  }
}

console.log(maxScore);
This script will handle the problem as per the constraints given. It will iterate through the tokens and try to gain a higher score by spending power on tokens which are smaller. When the power is less than the current token, it will try to gain power by spending on the token that is larger.