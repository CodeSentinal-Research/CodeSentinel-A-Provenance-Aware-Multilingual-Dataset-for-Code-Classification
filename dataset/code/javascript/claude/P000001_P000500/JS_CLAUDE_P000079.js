function convertSeconds(totalSeconds) {
    const hours = Math.floor(totalSeconds / 3600);
    const rem = totalSeconds % 3600;
    const minutes = Math.floor(rem / 60);
    const seconds = rem % 60;
    return [hours, minutes, seconds];
}

module.exports = { convertSeconds };
