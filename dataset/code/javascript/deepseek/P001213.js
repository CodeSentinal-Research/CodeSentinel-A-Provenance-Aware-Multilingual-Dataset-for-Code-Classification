Here is the JavaScript code for the given problem:

function isScrambled() {
  var A = process.argv[2];
  var B = process.argv[3];

  if (A.length !== B.length) {
    console.log("NO");
    return;
  }

  if (isScrambledHelper(A, B, A.length)) {
    console.log("YES");
  } else {
    console.log("NO");
  }
}

function isScrambledHelper(s1, s2, length) {
  if (length === 1) {
    return s1 === s2;
  }

  for (let i = 1; i < length; i++) {
    if (
      (isScrambledHelper(s1, s2.slice(0, i) + s2.slice(i), length - i) &&
      isScrambledHelper(s1.slice(0, i) + s1.slice(i), s2, length - i)
    ) {
      return true;
    }
  }

  return false;
}

isScrambled();

This script takes two command line arguments, A and B. It first checks if the lengths of A and B are equal. If not, it prints "NO" and ends the program. If they are equal, it calls the isScrambledHelper function with the two strings and their lengths. The helper function uses recursion and swapping to check if one string is a scrambled version of the other. If it can find a partition where one string is a scrambled version of the other, it prints "YES". If it can't find such a partition, it prints "NO".

You can run this script from the command line like this:

node script.js "ABCD" "BADC"

Replace "ABCD" and "BADC" with the strings you want to check.