Here is a simple JavaScript code that checks whether a string can be constructed by taking a substring of it and appending multiple copies.

function repeatedSubstringPattern(s) {
  const length = s.length;

  // Using brute force approach
  for (let i = 1; i * 2 <= length; i++) {
    if (length % i === 0) {
      const substring = s.slice(0, i);
      if (substring.repeat(length / i) === s) {
        return "Yes";
      }
    }
  }

  return "No";
}

// Testing the function
const s = prompt("Enter a string:");
console.log(repeatedSubstringPattern(s));

In this code, we are checking each substring of the input string `s` to see if it repeats exactly as a substring of `s`. If we find such a substring, we return "Yes". If we can't find a repeated substring, we return "No".

Please note that this solution is not the most efficient one, but it works fine for small inputs. For larger inputs, you might want to use a more efficient algorithm or pattern matching algorithm.