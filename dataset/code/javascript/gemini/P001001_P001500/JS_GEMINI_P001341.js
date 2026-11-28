// Helper function to evaluate readbinarywatch for problem constraints.
function readBinaryWatch(turnedOn) {
    const res = [];
    for (let h = 0; h < 12; h++) {
        for (let m = 0; m < 60; m++) {
            const hBits = h.toString(2).split('0').join('').length;
            const mBits = m.toString(2).split('0').join('').length;
            if (hBits + mBits === turnedOn) {
                res.push(`${h}:${m < 10 ? '0' : ''}${m}`);
            }
        }
    }
    return res;
}

module.exports = { readBinaryWatch };