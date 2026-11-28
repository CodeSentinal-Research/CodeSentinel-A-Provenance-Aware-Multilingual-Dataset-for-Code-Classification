function findLongestWord(S, dict) {
    let longest = '';
    dict.sort((a, b) => b.length - a.length);

    for (let word of dict) {
        if (wordInString(S, word)) {
            longest = word;
            break;
        }
    }

    return longest;
}

function wordInString(S, word) {
    let index = S.indexOf(word);

    while (index !== -1) {
        S = S.slice(0, index) + S.slice(index + word.length);
        index = S.indexOf(word);
    }

    return S.length === 0;
}

console.log(findLongestWord("iloveleetcode", ["ale","apple","monkey","plea"]));
console.log(findLongestWord("apple", ["a","b","c"]));