Here is the JavaScript code to solve the given problem:

function partition(s, m, dictionary) {
    let partitions = [];
    let wordBank = new Set(dictionary);
    let cache = {};
    
    function backtrack(start, currPartition) {
        if (currPartition.length === m && wordBank.has(currPartition.join(''))) {
            partitions.push(currPartition);
            return;
        }
        if (currPartition.length >= m) return;
        for (let i = start; i < s.length; i++) {
            let word = s.slice(start, i + 1);
            if (wordBank.has(word) && !cache[i + 1]) {
                currPartition.push(word);
                cache[i + 1] = true;
                backtrack(i + 1, currPartition);
                currPartition.pop();
                cache[i + 1] = false;
            }
        }
    }
    
    backtrack(0, []);
    return partitions;
}

This code uses a depth-first search approach to find all the partitions of the string `s` into dictionary words. The `cache` object is used to avoid duplicates in the same substring. For each start index, we try to split the string into words from `start` to the end. If the word is in the dictionary and it has not been used before, we add it to the current partition and continue the search from `i + 1`. If we found a valid partition, we add it to the results and continue the search.