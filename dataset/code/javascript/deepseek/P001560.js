Here is the JavaScript code which solves the problem:

function minWindow(s, t) {
    if (s.length == 0 || t.length == 0) {
        return "";
    }
    let map = new Map();
    for (let i = 0; i < t.length; i++) {
        if (map.has(t[i])) {
            map.set(t[i], map.get(t[i]) + 1);
        } else {
            map.set(t[i], 1);
        }
    }
    let l = 0, r = 0, formed = 0, required = t.length, found = {};
    while (r < s.length) {
        if (map.has(s[r])) {
            found[s[r]] = (found[s[r]] || 0) + 1;
            if (found[s[r]] == map.get(s[r])) {
                formed++;
            }
        }
        while (l <= r && formed == required) {
            if (r - l + 1 < r - i + 1) {
                r = l + r - l;
            } else {
                if (r - i + 1 < r - l + 1) {
                    l = r - r + i + 1;
                } else {
                    l = i;
                }
                if (map.has(s[l])) {
                    found[s[l]]--;
                    if (found[s[l]] < map.get(s[l])) {
                        formed--;
                    }
                }
            }
        }
        r++;
    }
    return s.slice(l, r + 1);
}

In this code, we use two pointers, l and r, to find the minimum window in S that contains all characters of T. We use a map to count the number of each character in T. If a character in T appears in S, we increment the count in the map. When the count of a character in T is found in S, we increment the count in the found map. We move the right pointer to the right. If all characters in T appear in S, we move the left pointer to the left. We keep moving the right pointer until we find a valid window and update the minimum window. If the count of a character in T is not found in S, we move the left pointer to the right.