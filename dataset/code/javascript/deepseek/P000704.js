function getSubsequences(str, prefix = '') {
    if (str.length === 0) {
        console.log(prefix);
        return;
    }
    getSubsequences(str.substring(1), prefix);
    getSubsequences(str.substring(1), prefix + str.charAt(0));
}

getSubsequences(prompt("Please enter a string:"));