Here is a simple recursive solution for the problem. 

This solution works by recursively trying all possible combinations until it finds one that leads to a win. It uses a Boolean array dp where dp[i] is true if it's possible to reach a state with sum i. The base case is when there are no more numbers to choose, i.e., if sum[i]==sum[j] for all i≠j.

function canIWin(maxChoosableInteger, desiredTotal) {
  if (desiredTotal <= 0) return true;
  if (maxChoosableInteger >= desiredTotal) return false;
  
  let sum = 0;
  for (let i = 1; i <= maxChoosableInteger; i++) {
    sum += i;
  }
  
  if (sum < desiredTotal) return false;

  let dp = new Array(desiredTotal + 1).fill(false);
  dp[0] = true;

  for (let i = 1; i <= maxChoosableInteger; i++) {
    for (let j = desiredTotal; j >= i; j--) {
      if (!dp[j - i] && !dp[j]) dp[j] = true;
    }
  }
  
  return dp[desiredTotal];
}

For the input handling, you can use a function like this:

function getInput() {
  let maxChoosableInteger = prompt("Enter the maximum choosable integer (1 to 20)");
  let desiredTotal = prompt("Enter the desired total (1 to 300)");
  
  if (maxChoosableInteger < 1 || maxChoosableInteger > 20 || desiredTotal < 1 || desiredTotal > 300) {
    alert("Invalid input. Please enter values between 1 and 20 for maxChoosableInteger and 1 and 300 for desiredTotal.");
    getInput();
  } else {
    return {maxChoosableInteger, desiredTotal};
  }
}

let {maxChoosableInteger, desiredTotal} = getInput();
alert(canIWin(maxChoosableInteger, desiredTotal) ? "True" : "False");
This code will ask for user input for maxChoosableInteger and desiredTotal, validate them and display the result of canIWin function.