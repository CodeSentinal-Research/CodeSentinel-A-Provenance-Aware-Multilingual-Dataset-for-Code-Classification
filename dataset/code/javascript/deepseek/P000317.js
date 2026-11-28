function wordPattern(pattern, str) {
  // Split the string into words
  const words = str.split(' ');

  // Check if the pattern matches the words
  for (let i = 0; i < words.length; i++) {
    if (pattern.indexOf(words[i]) !== pattern.indexOf(words[0])) {
      return "No";
    }
  }

  // If it passed the previous checks, return "Yes"
  return "Yes";
}