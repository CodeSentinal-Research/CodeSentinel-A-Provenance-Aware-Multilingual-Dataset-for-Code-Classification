Here is a JavaScript solution for the given problem. This solution uses a frequency map to count the frequency of each character and then sorts the frequencies in ascending order. The character with the highest frequency will be deleted if it occurs more than once.

function minDeletions(str) {
  let map = new Map();
  for (let char of str) {
    if (map.has(char)) {
      map.set(char, map.get(char) + 1);
    } else {
      map.set(char, 1);
    }
  }

  let frequencies = Array.from(map.values());
  frequencies.sort((a, b) => b - a);

  let deletions = 0;
  let i = 0;

  while (i < frequencies.length) {
    let repeat = i;
    while (repeat < frequencies.length && frequencies[repeat] >= frequencies[i]) {
      frequencies[repeat] -= frequencies[i];
      repeat++;
    }
    if (repeat > i) {
      deletions += frequencies[i];
    }
    i = repeat;
  }

  return deletions;
}

// Input handling
let input = process.argv[2];
console.log(minDeletions(input));

You can run this script with a command like `node script.js abcabc`. The script will print the minimum number of character deletions required to make the string's character frequencies unique.

Note: This solution assumes that the input string is a valid UTF-8 encoded string. If you are dealing with a string in a different encoding or format, you will need to adjust the solution accordingly.