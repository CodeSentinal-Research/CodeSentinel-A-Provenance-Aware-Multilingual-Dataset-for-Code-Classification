Here is a simple JavaScript solution using a regular expression to match the vowels (both lowercase and uppercase) in the string and replace them with an empty string:

function removeConsonants(S) {
    // Define the vowels
    var vowels = 'aeiouAEIOU';

    // Use the replace function to replace all vowels with an empty string
    var result = S.replace(/[^aeiouAEIOU]/g, '');

    // Return the result
    return result;
}

You can use the function by passing a string:

var S = "Hello World";
var result = removeConsonants(S);
console.log(result); // Outputs: "eoo"

This function will work for all strings, including those with special characters, spaces, and uppercase vowels.