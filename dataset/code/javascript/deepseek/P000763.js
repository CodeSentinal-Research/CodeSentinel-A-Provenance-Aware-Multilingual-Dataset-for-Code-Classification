function isMatch(s, p) {
    if (p === '') {
        return s === p;
    }

    if (s === '') {
        return p.split('').every(char => char === '*' && p.length > 1);
    }

    if (p[0] === '*') {
        for (let i = 0; i <= s.length; i++) {
            if (isMatch(s.substring(i), p.substring(1))) {
                return true;
            }
        }
        return false;
    }

    if (p[0] === s[0] || p[0] === '.') {
        return isMatch(s.substring(1), p.substring(1));
    }

    return false;
}