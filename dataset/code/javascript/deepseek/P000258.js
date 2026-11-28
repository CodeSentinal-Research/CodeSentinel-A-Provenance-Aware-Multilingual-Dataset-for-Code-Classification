Sure, here is the JavaScript code:

function sortString(s) {
  return s.split('').sort().join('');
}

let inputString = process.argv[2];
console.log(sortString(inputString));

This code will accept a string as an input argument from the command line. The `split('')` method is used to convert the string into an array of characters, the `sort()` method sorts the array in alphabetical order, and finally, the `join('')` method combines the sorted characters back into a string.