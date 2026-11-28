Here is the JavaScript code to solve the given problem:

function encodeStrings(arr) {
  // Check if the input is an array and all elements are strings
  if (!Array.isArray(arr) || arr.some(item => typeof item !== 'string')) {
    throw new Error('Input should be an array of strings');
  }

  // Check if the input array is not empty
  if (arr.length === 0) {
    throw new Error('Input array should not be empty');
  }

  // Join all strings in the array into a single string
  let encodedString = arr.join('');

  return { encodedString, decodedArray: arr };
}

function decodeStrings(obj) {
  // Check if the input is an object and has a 'encodedString' and 'decodedArray' property
  if (typeof obj !== 'object' || !('encodedString' in obj) || !('decodedArray' in obj)) {
    throw new Error('Input should be an object with an encoded string and a decoded array');
  }

  // Split the encoded string into an array of strings
  let decodedArray = obj.encodedString.split('');

  return decodedArray;
}

This code defines two functions, `encodeStrings` and `decodeStrings`, that encode and decode a list of strings into a single string and back to the original list, respectively. The function `encodeStrings` takes an array of strings as input, checks for errors, joins all strings in the array into a single string, and returns an object containing the encoded string and the decoded array. The function `decodeStrings` takes an object containing an encoded string and a decoded array as input, checks for errors, splits the encoded string into an array of strings, and returns the decoded array.