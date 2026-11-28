Here is a JavaScript solution using recursion:

function isMatch(s, p) {
    // base cases
    if (p === "" && s !== "") return false;
    if (p === s && p !== "") return true;

    // check if '*' matches
    if (p.length > 1 && p[1] === '*') {
        // if '*' matches the first character, check the rest
        if (p[0] === s || p[0] === '.' && s !== "") {
            return isMatch(s.substring(1), p);
        }
        // if '*' does not match the first character, check the rest
        else {
            return isMatch(s, p.substring(2));
        }
    }

    // check if '?' matches
    if (p.length === 1 && p[0] === '?' && s !== "") {
        return isMatch(s.substring(1), p.substring(1));
    }

    // check if '*' matches
    if (p.length > 1 && p[1] === '*') {
        return isMatch(s, p.substring(2));
    }

    // if neither '?' nor '*' matches, check if characters match
    if (p[0] === s[0] || p[0] === '.' && s[0] !== "") {
        return isMatch(s.substring(1), p.substring(1));
    }

    // if characters do not match
    return false;
}

This solution works by checking the first character of both strings against the first character of the pattern. If they match, it then recursively checks the rest of the strings and patterns. If the characters do not match, it returns false. If the pattern is "...", it checks if the first character of the pattern matches the first character of the string. If it does, it recursively checks the rest of the string and pattern. If the first character of the pattern does not match the first character of the string, it recursively checks the rest of the string and pattern. The base cases are when the pattern is empty and the string is also empty, or when the pattern and string are the same.