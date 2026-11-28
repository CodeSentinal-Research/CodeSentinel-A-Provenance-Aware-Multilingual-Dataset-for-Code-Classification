function capitalize(s) {
    return s.replace(/\b\w/g, c => c.toUpperCase());
}

module.exports = { capitalize };