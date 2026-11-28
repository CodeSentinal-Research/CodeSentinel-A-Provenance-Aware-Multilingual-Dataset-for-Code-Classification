Here is the JavaScript code for the problem:

function searchLongestString(input) {
    var maxLength = 0;
    var maxIndex = 0;
    for (var i = 0; i < input.length; i++) {
        if (input[i].length > maxLength) {
            maxLength = input[i].length;
            maxIndex = i;
        }
    }
    return maxIndex;
}
In this function, we loop through the input array to find the longest string. The loop iterates through the input array and each time it finds a string that is longer than the current longest string, it updates the longest string and its index. After it has looped through all the strings, it returns the index of the longest string.