Here is the JavaScript code that will solve the problem:

function reverseString(s) {
  // Check if input is a string
  if (typeof s !== 'string') {
    throw new Error('Input must be a string');
  }

  // Reverse the string
  let reversed = s.split('').reverse().join('');

  return reversed;
}

// Testing the function
console.log(reverseString('Hello')); // Outputs: 'olleH'

This function first checks if the input is a string. If it is not, it throws an error. Otherwise, it splits the string into an array of characters, reverses the array, and then joins the reversed array back into a string.