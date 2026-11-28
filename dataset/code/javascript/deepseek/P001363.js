function generateBinStrings(n) {
    let arr = [];
    function generateBinary(str, left, right) {
        if (left > right) {
            arr.push(str);
        } else {
            generateBinary(str + '0', left + 1, right);
            if (left < right) {
                generateBinary(str + '1', left + 1, right);
            }
        }
    }
    generateBinary("", 0, n);
    arr.sort();
    for(let i=0; i<arr.length; i++) {
        console.log(arr[i]);
    }
}

This code generates all binary strings of length `n` that do not contain two consecutive 1's. It does this by recursively generating binary strings by appending '0' and '1' to the end of the existing string. If the string already contains two consecutive '1's, it simply does nothing.

The generated strings are sorted before being printed, to ensure the output is lexicographically sorted.