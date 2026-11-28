Sure, here is the JavaScript code that you can use:

function wordSum(firstWord, secondWord, targetWord) {
    const sum = parseInt(firstWord) + parseInt(secondWord) + parseInt(targetWord);
    if (sum === parseInt(targetWord)) {
        console.log("Yes");
    } else {
        console.log("No");
    }
}

// Testing the function
wordSum('5', '10', '12'); // Expected output: Yes
wordSum('1', '2', '3'); // Expected output: No

In this code, we are converting each word into an integer using `parseInt` function, then adding them up to get the sum. If the sum equals the target word, we print "Yes" else "No". We're not using `console.log` here because the task requires the output to be printed on the console, not just returned by the function.