Here's a simple JavaScript code that can be used to search for files by extension. This function uses the `fs` module in Node.js to read the files and then filters them by extension.

const fs = require('fs');

function findFiles(fileNames, extension) {
  const filteredFiles = fileNames.filter(fileName => fileName.endsWith(extension));
  return filteredFiles;
}

// Test the function
const fileNames = ['file1.txt', 'file2.txt', 'file3.pdf', 'file4.jpg', 'file5.docx'];
const extension = '.txt';
const result = findFiles(fileNames, extension);
console.log(result); // Output: ['file1.txt', 'file3.pdf', 'file5.docx']

This function will return an array of file names that end with the specified extension. The `filter` method in JavaScript is used to create a new array with all elements that pass a test implemented by the provided function. In this case, the test is whether the file name ends with the specified extension.

Please note that this function only works with the Node.js environment. If you want to use this in a browser environment, you would need to use the `fs` module directly in the browser.