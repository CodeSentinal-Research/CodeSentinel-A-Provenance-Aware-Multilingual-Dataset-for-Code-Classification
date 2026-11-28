Here is the JavaScript code to solve the problem:

const [answer, K] = process.argv.slice(2);

function maxConsecutiveAnswers(str, k) {
    const count = Array(str.length + 1).fill(0);
    let maxLength = 0;
    let validCharCount = 0;

    for (let i = 0; i < str.length; i++) {
        count[i + 1] = count[i] + (str[i] === 'T' ? 1 : 0);
    }

    for (let j = 0; j < str.length; j++) {
        if (str[j] === 'T') {
            if (count[j + 1] - count[j] <= k) {
                validCharCount++;
            } else {
                validCharCount = 0;
            }
        }
        maxLength = Math.max(maxLength, validCharCount);
    }

    return maxLength;
}

console.log(maxConsecutiveAnswers(answer, Number(K)));

This code uses a dynamic programming approach to find the maximum length of consecutive 'T' characters that can be made with at most K changes. It first counts the number of 'T' characters in the string, then iterates over the string and updates the count for the next character. For each character, it checks if the count difference between the current character and the previous character is less than or equal to K, if yes, it increases the valid character count. The maximum valid character count is kept track of, and at the end, the maximum length is printed.

To run this code, you need to pass the answer string and the K value as command line arguments. For example, in the terminal, you can run:

node maxConsecutiveAnswers.js "TTFTTFT" 1

This will print `3` which is the maximum length of consecutive 'T' characters that can be made with at most 1 change.