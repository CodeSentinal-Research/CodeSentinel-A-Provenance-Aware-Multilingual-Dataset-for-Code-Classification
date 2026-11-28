function longestSubstringWithKDistinctCharacters(s, k) {
    let map = new Map();
    let res = 0;

    for (let start = 0, end = 0; end < s.length; end++) {
        if (!map.has(s[end])) map.set(s[end], 1);
        else map.set(s[end], map.get(s[end]) + 1);

        if (map.size === k + 1) {
            map.delete(s[start]);
            start++;
        }

        res = Math.max(res, end - start + 1);
    }

    return res;
}

const [s, k] = [readline(), readline()];
console.log(longestSubstringWithKDistinctCharacters(s, k));
This code first initializes a Map with one entry for the first character of the string, then iterates through the string, updating the count of each character. If the Map size equals K + 1, the start index is moved forward, removing the oldest entry from the Map. The maximum length of the substring is updated whenever a longer substring is found.