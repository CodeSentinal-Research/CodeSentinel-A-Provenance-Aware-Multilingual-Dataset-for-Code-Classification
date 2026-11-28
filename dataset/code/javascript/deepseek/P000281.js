function minWindow(s, t) {
    if (s.length == 0 || t.length == 0) return "";
    let map = new Map();
    for (let char of t) {
        map.set(char, (map.get(char) || 0) + 1);
    }
    let start = 0, startPos = -1, minLen = Infinity, count = 0;
    for (let i = 0; i < s.length; i++) {
        if (map.has(s[i]) && map.get(s[i]) > 0) {
            count++;
            map.set(s[i], map.get(s[i]) - 1);
        }
        if (count == t.length) {
            while (map.get(s[start]) < 0) {
                if (map.get(s[start]) == map.get(s[start]) - 1) {
                    map.set(s[start], map.get(s[start]) + 1);
                } else {
                    map.set(s[start], map.get(s[start]) - 1);
                }
                start++;
            }
            if (i - start + 1 < minLen) {
                minLen = i - start + 1;
                startPos = start;
            }
        }
    }
    if (startPos == -1) return "";
    return s.substring(startPos, startPos + minLen);
}