Here is a simple JavaScript function that counts the occurrences of a given character in a string:

function countCharacterOccurrences(S, C) {
    let count = 0;
    for(let i = 0; i < S.length; i++) {
        if(S[i] === C) {
            count++;
        }
    }
    return count;
}

This function works by initializing a count to 0, then looping through each character in the string. If the current character is the one we're looking for (C), we increment the count. At the end of the function, we return the count.

Now, to handle the input and output, you can use the following code:

let S = prompt("Enter a string:");
let C = prompt("Enter a character:");

let count = countCharacterOccurrences(S, C);
console.log("Count of '" + C + "' in '" + S + "' is: " + count);

This code will prompt the user to enter a string and a character, then call the `countCharacterOccurrences` function with these inputs. The count is then printed to the console.