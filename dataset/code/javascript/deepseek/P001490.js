Here is the JavaScript code:

process.stdin.on('data', (data) => {
    const binaryString = data.toString();
    let count = 0;
    let currentGroup = '';
    for (let i = 0; i < binaryString.length; i++) {
        if (binaryString[i] !== currentGroup[currentGroup.length - 1]) {
            currentGroup += binaryString[i];
        } else {
            if (currentGroup.length > 0) {
                count += currentGroup.length;
            }
            currentGroup = binaryString[i];
        }
    }
    if (currentGroup.length > 0) {
        count += currentGroup.length;
    }
    console.log(count);
});

This code reads a binary string from the standard input, then counts the number of substrings with the same number of 0s and 1s. The count is printed to the standard output.