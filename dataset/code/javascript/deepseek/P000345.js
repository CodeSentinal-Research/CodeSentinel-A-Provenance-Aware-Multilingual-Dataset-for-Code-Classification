Here is the JavaScript code to solve the problem. 

function checkSameCharacters(S1, S2) {
    // Check if both strings are not the same length
    if (S1.length !== S2.length) {
        console.log("No");
        return;
    }

    // Convert both strings to lowercase and split into arrays of characters
    const charArray1 = S1.toLowerCase().split('');
    const charArray2 = S2.toLowerCase().split('');

    // Create two empty objects to count the frequency of each character
    const charCount1 = {};
    const charCount2 = {};

    // For each character in the first string, increment its count in the object
    charArray1.forEach((char) => {
        charCount1[char] = (charCount1[char] || 0) + 1;
    });

    // For each character in the second string, decrement its count in the object
    charArray2.forEach((char) => {
        charCount2[char] = (charCount2[char] || 0) - 1;
    });

    // Check if the character counts are all 0
    for (let char in charCount1) {
        if (charCount2[char] !== charCount1[char]) {
            console.log("No");
            return;
        }
    }

    console.log("Yes");
}

This code will take two strings as input, convert them to lowercase, and split them into arrays of characters. It then counts the frequency of each character in each string and compares the counts. If all character counts are the same, it prints "Yes"; otherwise, it prints "No". 

Please note that this code does not handle invalid inputs. For example, if either of the inputs is not a string, it will fail. You might want to add additional error checking to ensure inputs are valid.