Here is a JavaScript solution for the problem:

function reverseOnlyLetters(S) {
  let arr = S.split("");
  let left = 0;
  let right = arr.length - 1;

  while (left < right) {
    if (!arr[left].match(/[a-z]/i)) {
      left++;
    } else if (!arr[right].match(/[a-z]/i)) {
      right--;
    } else {
      [arr[left], arr[right]] = [arr[right], arr[left]];
      left++;
      right--;
    }
  }

  return arr.join("");
}

This function works by iterating over the input string from both ends and swapping the characters if they are both letters. It uses a regular expression to check if a character is a letter.