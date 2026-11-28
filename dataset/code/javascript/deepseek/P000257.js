Here is a simple JavaScript function to check if two strings are anagrams of each other:

function checkAnagram(s1, s2) {
  // Convert strings to lower case and sort them
  const sortedS1 = [...s1.toLowerCase()].sort().toString();
  const sortedS2 = [...s2.toLowerCase()].sort().toString();

  // Check if sorted strings are equal
  if (sortedS1 === sortedS2) {
    console.log("Yes");
  } else {
    console.log("No");
  }
}

This function works by first converting the input strings to lower case and sorting the characters in them. It then compares if the sorted strings are equal. If they are, the input strings are anagrams of each other, and the function prints "Yes". Otherwise, it prints "No".

Please note that this function only works for alphabetic characters and does not work with special characters, numbers, or spaces. If you want to handle these cases as well, you would need to adjust the function to handle special characters and numbers.