function firstNonRepeatingCharacter(s) {
  let frequency = new Map();

  // Fill the frequency map
  for (let i = 0; i < s.length; i++) {
    frequency.set(s[i], (frequency.get(s[i]) || 0) + 1);
  }

  // Find the first non-repeating character
  for (let i = 0; i < s.length; i++) {
    if (frequency.get(s[i]) === 1) {
      return i;
    }
  }

  // If no non-repeating character is found
  return -1;
}