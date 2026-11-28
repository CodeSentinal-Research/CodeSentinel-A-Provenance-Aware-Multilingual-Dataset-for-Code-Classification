Here is a simple JavaScript solution using recursion to generate all K-length strings from given characters:

function generateStrings(chars, k) {
  if (k === 0) {
    return [];
  }

  const result = [];

  for (let i = 0; i < chars.length; i++) {
    const char = chars[i];
    const remainingChars = chars.slice(0, i).concat(chars.slice(i + 1));
    const remainingStrings = generateStrings(remainingChars, k - 1);
    for (const str of remainingStrings) {
      result.push(char + str);
    }
  }

  return result.sort();
}

function solveProblem(n, characters, k) {
  if (n < 1 || n > 26 || k < 1 || k > 10) {
    console.log('Invalid input');
    return;
  }

  const chars = Array.from({ length: n }, (_, i) => String.fromCharCode('a'.charCodeAt() + i));
  const result = generateStrings(chars, k);

  console.log(result);
}

solveProblem(5, 'abc', 3);

In this code, `generateStrings` is a recursive function that generates all K-length strings from the given characters. It uses a technique similar to backtracking to generate the strings. For each character, it generates strings with the remaining characters (excluding the current one), and then adds the current character to each of these strings.

The `solveProblem` function validates the input, generates all K-length strings from the given characters, and prints them in lexicographical order.

Please note that the input is hardcoded here. You can modify this function to accept the input from the user or from a file, if needed.