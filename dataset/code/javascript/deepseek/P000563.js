Here is the JavaScript code for the given problem:

function wordLadder(beginWord, endWord, wordList) {
  // Create a set from the word list to find neighbors in O(1) time
  const neighbors = new Set(wordList);
  // Use a set to track visited words and the depth of each word
  const visited = new Set([beginWord]);
  let queue = [[beginWord, 1]];

  while(queue.length > 0) {
    const [word, depth] = queue.shift();
    // Check if we've reached the end word
    if(word === endWord) {
      return depth;
    }
    // Generate all possible neighbors
    for(let i = 0; i < word.length; i++) {
      for(let charCode = 'a'.charCodeAt(0); charCode <= 'z'.charCodeAt(0); charCode++) {
        const newWord = word.slice(0, i) + String.fromCharCode(charCode) + word.slice(i + 1);
        if(neighbors.has(newWord) && !visited.has(newWord)) {
          visited.add(newWord);
          queue.push([newWord, depth + 1]);
        }
      }
    }
  }

  // If we've reached here, no path found
  return 0;
}

This code will take as input a beginWord, endWord and a list of words, and it will find the shortest transformation sequence from beginWord to endWord, or return 0 if no transformation exists. The transformation sequence is found by changing exactly one character at a time, and every intermediate word must exist in the dictionary.