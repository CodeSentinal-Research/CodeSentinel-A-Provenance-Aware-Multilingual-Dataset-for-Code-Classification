Here is the JavaScript code:

function detectCapital(word) {
  // Check if the word is undefined or null
  if (word === undefined || word === null) {
    console.log('No');
    return;
  }

  // Check if the word is empty
  if (word === '') {
    console.log('No');
    return;
  }

  // Check if the first character is uppercase
  if (word[0] === word[0].toUpperCase() && word[0] !== word[0].toLowerCase()) {
    // Check if all characters are uppercase
    for (let i = 1; i < word.length; i++) {
      if (word[i] !== word[i].toUpperCase() && word[i] !== word[i].toLowerCase()) {
        console.log('No');
        return;
      }
    }
  } else {
    // Check if the first character is not uppercase
    for (let i = 1; i < word.length; i++) {
      if (word[i] === word[i].toUpperCase() && word[i] === word[i].toLowerCase()) {
        console.log('No');
        return;
      }
    }
  }

  console.log('Yes');
}

// Test the function
detectCapital('Hello');
detectCapital('hello');
detectCapital('HELLO');
detectCapital('1234');
This function will first check if the word is undefined or null, if it is, print 'No' and return. If the word is empty, print 'No' and return. Then it will check if the first character is uppercase, if it is, it will check if all characters are uppercase, if not, print 'No' and return. If the first character is not uppercase, it will check if all characters are not uppercase, if not, print 'No' and return. If all checks pass, print 'Yes'.