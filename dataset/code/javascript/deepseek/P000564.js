Here is the JavaScript code for Word Ladder II problem.

var findLadders = function(beginWord, endWord, wordList) {
    let map = {}, queue = [[beginWord, [beginWord]]], res = [];
    wordList.forEach(word => map[word] = word);
    while (queue.length) {
        let len = queue.length, currentLevel = [];
        for (let i = 0; i < len; i++) {
            let [curWord, path] = queue.shift();
            if (curWord === endWord) res.push(path);
            for (let j = 0; j < curWord.length; j++) {
                for char in 'abcdefghijklmnopqrstuvwxyz' {
                    let newWord = curWord.substring(0, j) + char + curWord.substring(j + 1);
                    if (map[newWord]) {
                        if (!path.includes(map[newWord]) && path.includes(wordList)) {
                            queue.push([newWord, path.concat(map[newWord])]);
                        }
                    }
                }
            }
        }
    }
    return res;
};

In this code, we use a Breadth-First Search (BFS) algorithm to find all shortest transformation sequences from `beginWord` to `endWord`. The `map` object is used to make a graph traversal, where each key-value pair in `map` represents a word and its corresponding transformation.

The BFS algorithm works by traversing all possible paths from `beginWord` to `endWord` by changing each character in a word, and checking if the resulting word is in the `wordList` and has not been visited before. If it is, we add this path to the `queue` and start a new level of the BFS. This process continues until there are no more words in the `queue`. At the end of this process, `res` holds all shortest transformation sequences from `beginWord` to `endWord`.