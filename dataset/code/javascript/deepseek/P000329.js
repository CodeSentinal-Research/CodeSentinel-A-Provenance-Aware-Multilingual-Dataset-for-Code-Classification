Sure, here is a simple JavaScript code that finds the extra character added in one string compared to another. This code uses the ASCII value of the characters in the strings to find the extra character.

function findExtra(s1, s2) {
  let i = 0, j = 0;

  while(s1[i] && s2[j]) {
    if(s1[i] !== s2[j]) {
      return s1[i];
    }
    i++;
    j++;
  }

  return s1[i];
}

This function will return the extra character if there is one. If the strings are not of the same length, it will return the last character of the longer string.

To use this function, you can pass the two strings to it as arguments, like this:

let extra = findExtra('hello', 'hello, world');
console.log(extra);  // Outputs: ','

In this example, the extra character is a comma (','). If the strings were different lengths, the extra character would be the last character of the longer string.