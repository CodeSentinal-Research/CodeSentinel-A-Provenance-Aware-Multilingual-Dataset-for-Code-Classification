function countFrequency(arr, target) {
    return arr.reduce((acc, curr) => (curr === target ? acc + 1 : acc), 0);
}

module.exports = { countFrequency };