function countCharacters(s) {
    if(s === null || s.length === 0) {
        throw new Error('Input string is null or empty');
    }

    let frequencyMap = new Map();

    for(let char of s) {
        if(!frequencyMap.has(char)) {
            frequencyMap.set(char, 1);
        } else {
            frequencyMap.set(char, frequencyMap.get(char) + 1);
        }
    }

    return frequencyMap;
}