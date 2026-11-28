function countDistinctSubstrings(str) {
    let set = new Set();
    let n = str.length;
    for(let i = 0; i < n; i++) {
        let subStr = '';
        for(let j = i; j < n; j++) {
            subStr += str[j];
            set.add(subStr);
        }
    }
    return set.size;
}

console.log(countDistinctSubstrings(readline())); // readline function is not defined
This JavaScript code uses a Set data structure to hold the distinct substrings. The `set.add(subStr)` line is used to add the current substring to the set. The `set` automatically removes any duplicate entries because it only allows unique values. The size of the set is then returned, which represents the count of distinct substrings.