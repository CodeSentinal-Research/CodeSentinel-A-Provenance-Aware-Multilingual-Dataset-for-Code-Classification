function toggleCase(s) {
    return s.split('').map(c => {
        if (c === c.toUpperCase()) return c.toLowerCase();
        return c.toUpperCase();
    }).join('');
}

module.exports = { toggleCase };