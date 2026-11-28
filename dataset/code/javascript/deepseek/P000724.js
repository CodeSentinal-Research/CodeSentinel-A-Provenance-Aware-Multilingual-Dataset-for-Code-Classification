Here is a JavaScript solution for the given problem. This solution uses a depth-first search approach to find the maximum length of concatenated string with unique characters.

function maxLength(n, words) {
    let maxLen = 0;
    let wordSet = new Set();
    let dfs = (index, curStr) => {
        if (curStr.length > maxLen) {
            maxLen = curStr.length;
        }
        for (let i = index; i < n; i++) {
            if (words[i].length + curStr.length > 26) {
                continue;
            }
            if (!wordSet.has(curStr + words[i])) {
                wordSet.add(curStr + words[i]);
                dfs(i + 1, curStr + words[i]);
            }
        }
    };
    dfs(0, '');
    return maxLen;
}

This function uses a depth-first search (dfs) approach to solve the problem. It starts from the first word and recursively checks all possible combinations of the remaining words. The `wordSet` is a set to store all the combinations that have not been visited before. The `maxLen` is used to store the maximum length of the concatenated string. The `dfs` function is a recursive function that takes an index and a current string as arguments. For each word in the remaining words, if the concatenated string with the current word and the remaining words does not exist in the set, it is added to the set and the current string is updated. The function returns the maximum length.