Here is the JavaScript code to toggle the case of each character in a string.

function toggleCase(s) {
    let toggledString = '';
    for(let i = 0; i < s.length; i++) {
        if(s[i] === s[i].toLowerCase()) {
            toggledString += s[i].toUpperCase();
        } else {
            toggledString += s[i].toLowerCase();
        }
    }
    return toggledString;
}

let S = 'Hello World!';
console.log(toggleCase(S)); // Outputs: hELLO wORLD!

In this code, we iterate over each character in the string and toggle its case. We use the ASCII values of the characters to determine if they are uppercase or lowercase. If the ASCII value of a character falls in the range of lowercase letters (65-90), it's uppercase. Otherwise, it's lowercase.