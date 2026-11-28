function reversePrefix(inputString, charC) {
    let str = inputString.split('');
    let index = str.indexOf(charC);
    if (index !== -1) {
        str.splice(0, index + 1);
        str.push.apply(str, str.slice(0, index).reverse());
    }
    return str.join('');
}

process.stdin.on('data', (data) => {
    const [inputString, charC] = data.toString().trim().split(' ');
    console.log(reversePrefix(inputString, charC));
});
This JavaScript program reads a string and a character from the input, splits the string into an array, finds the index of the character in the array, and then reverses the prefix of the string that ends at the first occurrence of the character. If the character does not exist in the string, it simply leaves the string unchanged. The program then prints the modified string.