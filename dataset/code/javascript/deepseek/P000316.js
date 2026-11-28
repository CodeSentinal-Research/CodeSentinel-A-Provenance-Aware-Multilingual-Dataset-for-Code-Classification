Here is the JavaScript code for the problem:

function isIsomorphic(s, t) {
    if (s.length !== t.length) {
        return false;
    }
    let mapS = {};
    let mapT = {};
    for (let i = 0; i < s.length; i++) {
        if (mapS[s[i]] && mapT[t[i]] && mapS[s[i]] !== mapT[t[i]]) {
            return false;
        }
        if (!mapS[s[i]] && !mapT[t[i]]) {
            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        } else {
            return false;
        }
    }
    return true;
}
This function `isIsomorphic` takes two strings `s` and `t` as inputs. It first checks if the two strings have the same length. If they don't, they cannot be isomorphic. Then, for each character in the strings, it checks if it's already in the mapping. If it is, it checks if the corresponding character in the other string maps to the same character. If it doesn't, it returns false. If it is, continue to the next character. If it is the first character, it adds the mapping in the maps object.