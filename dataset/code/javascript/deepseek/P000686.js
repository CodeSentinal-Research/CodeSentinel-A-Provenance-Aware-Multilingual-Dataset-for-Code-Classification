Here is the JavaScript code for the problem:

function reverseString(s) {
  if (s === "") return "";
  return reverseString(s.substr(1)) + s.charAt(0);
}

console.log(reverseString("Hello World"));  // "dlroW olleH"

This function uses recursion to reverse the string. The function `reverseString` takes a string `s` as input and checks if `s` is an empty string. If it is, it returns an empty string. Otherwise, it calls itself recursively with the string `s` sliced from the index 1 onwards and concatenates the first character of `s` to the end of the reversed string.

The base case for the recursion is when `s` is an empty string. In this case, the function simply returns an empty string.

In the recursive case, the function splits the string `s` into the first character (`s.charAt(0)`) and the rest of the string (`s.substr(1)`). It then concatenates this reversed substring with the first character of `s` to get the final reversed string.

Note: Be aware that this implementation is not optimized for large strings as it can have performance issues with recursion. A more efficient solution would use a loop or a stack.