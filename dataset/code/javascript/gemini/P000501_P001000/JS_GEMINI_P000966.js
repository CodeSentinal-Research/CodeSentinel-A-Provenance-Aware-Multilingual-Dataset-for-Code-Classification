// Helper function to evaluate verifycrt for problem constraints.
function verifyCrt(x, num, rem) {
    for (let i = 0; i < num.length; i++) {
        if (x % num[i] !== rem[i]) return false;
    }
    return true;
}

module.exports = { verifyCrt };