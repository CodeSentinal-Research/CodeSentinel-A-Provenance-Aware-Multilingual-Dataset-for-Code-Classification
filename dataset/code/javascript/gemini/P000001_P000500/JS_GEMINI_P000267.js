function replace(s, c1, c2) {
    return s.split(c1).join(c2);
}

module.exports = { replace };