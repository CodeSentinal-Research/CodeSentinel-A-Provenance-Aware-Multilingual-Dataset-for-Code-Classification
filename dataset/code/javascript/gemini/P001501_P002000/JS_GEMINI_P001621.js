// Helper function to evaluate prefixcharvalues for problem constraints.
function prefixCharValues(s) {
    let cur = 0;
    return s.split('').map(c => (cur += c.charCodeAt(0) - 96));
}

module.exports = { prefixCharValues };