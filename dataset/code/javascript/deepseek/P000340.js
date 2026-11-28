Here is the JavaScript code for your problem:

function maxWords(text, broken) {
  const textArray = text.split(' ');
  const brokenArray = broken.split(' ');

  let count = 0;

  for (let i = 0; i < textArray.length; i++) {
    if (brokenArray.includes(textArray[i])) {
      count++;
    }
  }

  return count;
}

This function takes two arguments: a text string and a string of broken letters. It splits the text string into an array of words and the broken letters into an array of words. Then, it iterates through the text array, checking if each word is included in the broken array. If a word is found to be broken, it increments the count. Finally, it returns the count.