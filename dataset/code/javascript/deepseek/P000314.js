Here's the code:

function convertToTitle(columnNumber) {
    if(columnNumber <= 0){
        throw new Error('Invalid input: Column number should be greater than zero.');
    }
    var title = '';
    while(columnNumber > 0){
        columnNumber--;
        title = String.fromCharCode(columnNumber % 26 + 'A'.charCodeAt(0)) + title;
        columnNumber = Math.floor(columnNumber / 26);
    }
    return title;
}

This code works by continuously dividing the input by 26 (since we're working with Excel column titles, which are based on 26 letters) and appending the result to the beginning of the title string. This will work for any column number from 1 to 2^31 - 1 (as long as the input is within this range).

For example, if you run `convertToTitle(51)`, it would return `"ZA"`. If you run `convertToTitle(26)`, it would return `"Z"`, and so on.