Here is the code:

function sortCharacters(str) {
  const frequency = new Map();
  for (let char of str) {
    if (frequency.has(char)) {
      frequency.set(char, frequency.get(char) + 1);
    } else {
      frequency.set(char, 1);
    }
  }

  const sortedChars = [...frequency.keys()].sort((a, b) => {
    if (frequency.get(b) - frequency.get(a) !== 0) {
      return frequency.get(b) - frequency.get(a);
    }
    return a.localeCompare(b);
  });

  let result = '';
  for (let char of sortedChars) {
    result += char.repeat(frequency.get(char));
  }

  return result;
}

// testing the function
console.log(sortCharacters('tree')); // ttttrrree
console.log(sortCharacters('aabcccddddeeff')); // dddcccaaa

This function uses a `Map` to count the frequency of each character in the string. Then it sorts the keys of the map in descending order based on the frequency and lexicographical order (i.e., when both characters are the same). It repeats each character the number of times it appears in the sorted list, and finally returns the result.