function toggleCase(s) {
    return s.split('').map(c =>
        c === c.toUpperCase() ? c.toLowerCase() : c.toUpperCase()
    ).join('');
}

module.exports = { toggleCase };
