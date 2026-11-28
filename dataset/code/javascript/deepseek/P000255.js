Here is the JavaScript code for the problem:

function removeVowels(s) {
  // Create a regular expression to match all vowels
  const re = /[aeiouAEIOU]/g;

  // Use the replace method to remove all vowels
  const result = s.replace(re, '');

  // Return the result
  return result;
}

This function uses the regular expression `/[aeiouAEIOU]/g` to match all vowels in the string `s` and replace them with an empty string. The `g` flag at the end of the regular expression is for global search and replace operations.