function reverseWordsInString(S) {
  let words = S.split(' '); // split the string into words
  let reversedWords = words.reverse(); // reverse the order of words
  let reversedString = reversedWords.join(' '); // join the words back into a string
  return reversedString;
}

console.log(reverseWordsInString('Hello World')); // Output: 'World Hello'
console.log(reverseWordsInString('JavaScript Reverse')); // Output: 'Reverse JavaScript'