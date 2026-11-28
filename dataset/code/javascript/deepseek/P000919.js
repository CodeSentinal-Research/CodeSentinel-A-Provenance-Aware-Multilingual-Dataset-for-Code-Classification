Here is the JavaScript code to solve the problem:

function countDigits(N) {
    let evenCount = 0;
    let oddCount = 0;
    
    for (let digit of N.toString()) {
        if (digit % 2 === 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    return {
        evenCount: evenCount,
        oddCount: oddCount
    };
}

console.log(countDigits(123456));

This code works by iterating through each digit in the input number and counting the number of even and odd digits. The digit is obtained by converting the number to a string and iterating through each character in the string. If the character is an even digit, it is counted as even, otherwise it is counted as odd.