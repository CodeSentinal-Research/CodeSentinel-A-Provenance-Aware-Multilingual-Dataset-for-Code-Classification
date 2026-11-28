Here is the JavaScript code for the given problem:

function generateAbbreviations(word) {
  const n = word.length;
  const res = [];

  // Function to get all permutations of the word
  const permutations = (arr, i) => {
    if (i === n) {
      res.push(arr.join(''));
      return;
    }

    permutations(arr, i + 1);

    // If the next character is the same, add a count
    if (i < n - 1 && word[i] === word[i + 1]) {
      let count = 2;
      while (i < n - 1 && word[i] === word[i + 1]) {
        i++;
        count++;
      }
      arr[arr.length - 1] += count;
      permutations(arr, i + 1);
    }
  };

  permutations([word[0]], 1);

  // Sort the abbreviations in lexicographical order
  res.sort();
  return res;
}

// Test the function
console.log(generateAbbreviations('apple'));

This function generates all the abbreviations by replacing consecutive characters with their counts. It handles the input by checking if the next character is the same. If it is, it adds a count. The function then sorts the abbreviations in lexicographical order.